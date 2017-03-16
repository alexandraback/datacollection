from  itertools import product, combinations
from operator import mul

T = int(raw_input())
print "Case #1:"

R,N,M,K = [int(n) for n in raw_input().split(" ")]

list_nums = list(product(range(2,M+1), repeat=N))
list_products = [None]*len(list_nums)
for i in range(len(list_nums)):
    list_products[i] = set()
    arr = list_nums[i]
    for j in range(N+1):
        for sub_arr in combinations(arr,j):
            list_products[i].add(reduce(mul, sub_arr,1))


for _ in range(R):
    arr = [int(n) for n in raw_input().split(" ")]
    found = False
    for i in range(len(list_nums)):
        list_p = list_products[i]
        is_subset = True
        for a in arr:
            if a not in list_p:
                is_subset = False

        if is_subset:
            print "".join([str(c) for c in list_nums[i]])
            found = True            
            break

    if not found:
        print str(M)*N
