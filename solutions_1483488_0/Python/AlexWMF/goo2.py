from __future__ import print_function

count = int(raw_input())

inp = [[int(x) for x in raw_input().split(' ')] for i in range(0, count)]

index = 0
for i in inp:
    A = i[0]
    B = i[1] 

    
    nums = set()
    for e in range(A, B+1):
        d = str(e)
        for n in range(1, len(d)):
            rec = int(d[-n:] + d[:-n])
            if rec > e and rec <= B:
                nums.add(str(e) + str(rec))
    index += 1
    print('Case #', index, ': ', len(nums), sep='') 