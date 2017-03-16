import sys
import re
import itertools


T = int(sys.stdin.readline().strip())
for i in xrange(T):
    K, L, S = (int(x) for x in sys.stdin.readline().strip().split())
    keys = sys.stdin.readline().strip()
    target = sys.stdin.readline().strip()

    for letter in target:
        if letter not in keys:
            print 'Case #{}: {}'.format(i+1, 0.0)
            break
    else:
        if len(set(keys)) == 1:
            print 'Case #{}: {}'.format(i+1, 0.0)
        else:
            total = 0
            instances = 0
            max_instances = 0
            for monkey_string in itertools.product(keys, repeat=S):
                monkey_string = ''.join(monkey_string)
                # print monkey_string
                total += 1
                string_instances = len(re.findall('(?={})'.format(target), monkey_string))
                instances += string_instances
                if string_instances > max_instances:
                    max_instances = string_instances
            print 'Case #{}: {}'.format(i+1, float(max_instances)-(float(instances)/total))
