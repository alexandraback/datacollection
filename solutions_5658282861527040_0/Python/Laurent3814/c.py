n = int(raw_input())

for i in range(n):
    nums = raw_input().split(" ")
    counter = 0
    a,b,k = int(nums[0]), int(nums[1]), int(nums[2])
    for t in range(a):
        for u in range(b):
            if t&u <k:
                
                counter +=1
    print "Case #%d: %d"%(i+1,counter)
