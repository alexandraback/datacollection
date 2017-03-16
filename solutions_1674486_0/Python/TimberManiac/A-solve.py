import pprint
from collections import defaultdict

f = open('A-small.in')
line_count = int(f.readline())

cases = []

for i in range(line_count):
    sub_classes_by_class = []

    test_count = int(f.readline())

    for i in range(test_count):
        input_parts = list(int(part) for part in f.readline().strip().split(' '))

        sub_class_count = int(input_parts[0])

        assert(len(input_parts) == sub_class_count + 1)

        sub_classes = [int(p)-1 for p in input_parts[1:]]

        sub_classes_by_class.append(sub_classes)

    cases.append(sub_classes_by_class)

print('Input:')
pprint.pprint(cases)
print('')

def solve(case):
    sub_class_dict = defaultdict(list)

    for class_id, sub_classes in enumerate(case):
        for sub_class in sub_classes:
            sub_class_dict[class_id].append(sub_class)

    super_class_dict = defaultdict(list)

    for class_id, sub_classes in sub_class_dict.items():
        for sub_class in sub_classes:
            super_class_dict[sub_class].append(class_id)

    leaf_classes = [i for i in range(len(case)) if i not in sub_class_dict]

    final_super_classes = {}

    print('Sub-classes: ', sub_class_dict)
    print('Super-classes: ', super_class_dict)
    print('Leaf-classes: ', leaf_classes)

    for leaf_class in leaf_classes:
        get_super_classes(leaf_class, super_class_dict, final_super_classes)

    for class_id, scs in final_super_classes.items():
        print(class_id, ':', scs)
        if len(scs) != len(set(scs)):
            print('{0}: {1} != {2}'.format(class_id, scs, set(scs)))
            return True
        else:
            print('{0}: {1} == {2}'.format(class_id, scs, set(scs)))

    return False

def get_super_classes(class_id, super_class_dict, final_super_classes):
    if class_id == []:
        return []

    if class_id not in final_super_classes:
        # Add immediate super-classes
        l = super_class_dict[class_id]
        # Append super-classes of those super-classes
        super_classes_of_sc = [get_super_classes(s, super_class_dict, final_super_classes) for s in super_class_dict[class_id]]
        for x in super_classes_of_sc:
            for y in x:
                l.append(y)
        # Set dictionary entry
        final_super_classes[class_id] = l

    return final_super_classes[class_id]

out_lines = []
out_file = open('A-small.out', 'w')

for i, case in enumerate(cases, 1):
    solution = solve(case)
    out_lines.append('Case #{0}: {1}'.format(i, 'Yes' if solution else 'No'))
    out_file.write('Case #{0}: {1}\n'.format(i, 'Yes' if solution else 'No'))

out_file.close()
print(out_lines)