import fileinput 

input = fileinput.input()

def do_case(case_num):
    [max_shyness, shynesses] = next(input).rstrip().split(' ')
    shynesses = [int(c) for c in shynesses]
    total_clapping = 0
    num_to_add = 0
    for (shyness_level, num_at_level) in enumerate(shynesses):
        if num_at_level > 0:
            add_for_this_level = max(0, shyness_level - total_clapping)
            num_to_add += add_for_this_level
            total_clapping += num_at_level + add_for_this_level
    print "Case #%d: %d" % (case_num, num_to_add)
        
T = int(next(input))
for case_num in range(1, T+1):
    do_case(case_num)

