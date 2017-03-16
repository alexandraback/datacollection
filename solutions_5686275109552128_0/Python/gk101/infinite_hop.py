import math

def min_needed(pancakes):
    max_stack = max(pancakes)
    if max_stack <= 3:
        return max_stack
    
    min_t = 10000000
    for wait_t in range(1, max_stack + 1):
        distr_t = 0
        for stack_size in pancakes:
            if stack_size > wait_t:
                distr_t += math.ceil((stack_size - wait_t) / float(wait_t))
            
            if distr_t + wait_t > min_t:
                break
        # print "wait:", wait_t, "distr:", distr_t, "total:", wait_t + distr_t
        min_t = min(min_t, distr_t + wait_t)
    
    return min_t

file_name = 'B-small-attempt1.in'
out = open('small_pancakes1.out', 'w')
with open(file_name) as f:
    T = int(next(f))
    count = 0
    case = 1
    
    for line in f:
        if count % 2 == 1:
            c = [int(i) for i in line.strip().split()]
            a = min_needed(c)
            # out.write(" ".join(str(i) for i in c)+"\n")
            out.write("Case #%d: %d\n" % (case, a))
            case += 1
        count += 1

out.close()


# T = int(raw_input())
# count = 0
# case = 1
    
# while count < T:
    # c = [int(i) for i in raw_input().strip().split()]
    # a = min_needed(c)
    
    # print "Case #%d: %d\n" % (count + 1, a)
    # count += 1
