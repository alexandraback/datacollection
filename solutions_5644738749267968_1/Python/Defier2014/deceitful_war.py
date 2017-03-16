import copy


def dwar(test):
    current = 0
    if not test['naomi']:
        return current
    for i in sorted(test['naomi']):
        if i > min(test['ken']):
            current += 1
            test['naomi'].remove(min(test['naomi']))
            test['ken'].remove(min(test['ken']))
        else:
            test['naomi'].remove(min(test['naomi']))
            test['ken'].remove(max(test['ken']))
    return current


def war(test):
    current = 0
    if not test['naomi']:
        return current
    for i in sorted(test['naomi'])[::-1]:
        if i > max(test['ken']):
            current += 1
            test['naomi'].remove(min(test['naomi']))
            test['ken'].remove(min(test['ken']))
        else:
            test['naomi'].remove(max(test['naomi']))
            bigger = []
            for j in test['ken']:
                if j > i:
                    bigger.append(j)
            test['ken'].remove(min(bigger))
    return current

def main():
    tests = {'count': 0, 'tests': []}
    test = {}
    with open('d.in', 'r') as readfile:
        for i, l in enumerate(readfile):
            if i == 0:
                tests['count'] = int(l.strip())
            elif (i - 1) % 3 == 0:
                if test:
                    tests['tests'].append(test)
                test = {}
                test['num'] = int(l.strip())
            elif (i - 1) % 3 == 1:
                test['naomi'] = [float(j) for j in l.strip().split(' ')]
            elif (i - 1) % 3 == 2:
                test['ken'] = [float(j) for j in l.strip().split(' ')]

        if test:
            tests['tests'].append(test)

    with open('d.out', 'wb') as writefile:
        i = 1
        for test in tests['tests']:
            dwar_test = copy.deepcopy(test)
            writefile.write('Case #%d: %d %d\n' %
                            (i, dwar(dwar_test), war(test)))
            i += 1
            # break

if __name__ == '__main__':
    main()
