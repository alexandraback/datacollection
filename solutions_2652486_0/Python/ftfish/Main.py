import itertools,operator


def getsubsets(seq):
    for i in range(len(seq)+1):
        for j in itertools.combinations(seq, i):
            yield j
    
if __name__ == '__main__':
    Tn = int(raw_input())
    for Tc in xrange(1, Tn + 1):
        R, N, M, K = map(int, raw_input().split())
        results = []
        for i in xrange(R):
            results.append(map(int, raw_input().split()))
            
        numbers = list(itertools.combinations_with_replacement(range(2,M+1), N))
        numbers_n = len(numbers)
        
        counter = {}
        arr = {}
        for num in numbers:
            subsets = list(getsubsets(num))
            subsets_n = len(subsets)
            for subset in subsets:
                prod = reduce(operator.mul, subset, 1)
                counter[prod] = counter.get(prod, 0) + 1
                arr[prod] = arr.get(prod, []) + [num]
                
#         print sorted(counter.items())
#         print arr
        for k,v in arr.items():
            arr[k] = set(v)
        
        print 'Case #%d:' % Tc
        
        
        for i in xrange(R):
            curres = set(numbers)
            for prod in results[i]:
                curres.intersection_update(arr[prod])
                if len(curres) == 1:
                    break
            print ''.join([str(x) for x in curres.pop()])
                
        
        
        
