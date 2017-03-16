import time
from itertools import chain, combinations

def all_subsets(ss):
  return chain(*map(lambda x: combinations(ss, x), range(0, len(ss)+1)))

def solve(integers):
    result = []
    integers.sort()
    index = 3
    length = len(integers)
    
    while index < length:
        largest = integers[index]
        smaller = []; smaller_append = smaller.append
        
        for i in integers:
            if i <= largest:
                smaller_append(i)
            else:
                break
        
        sum_cache = {}

        for subset in all_subsets(smaller):
            s = sum(subset)
            if s in sum_cache:
                result.append(sum_cache[s])
                result.append(subset)
                return result
            else:
                sum_cache[s] = subset
        
        index += 1
    
    return 'Impossible'


def main():
    input = open('C-small-attempt0.in')
    output = open('output.txt', 'w')
    total_case_num = int(input.readline().strip())
    
    for case_num in range(1, total_case_num + 1):
        integers = [int(x) for x in input.readline().strip().split(" ")[1:]]
        result = solve(integers)
        output.write("Case #%s:\n" % case_num)
        
        if result == 'Impossible':
            output.write("Impossible\n")
        else:
            for subset in result:
                output.write("%s\n" % " ".join([str(x) for x in subset]))

if __name__ == '__main__':
    #solve("1111 2222")
    #s = time.time()
    #solve("1000000 2000000")
    #print time.time() - s
    main()

