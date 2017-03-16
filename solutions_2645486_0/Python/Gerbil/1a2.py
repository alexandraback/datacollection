from operator import mul

def problem(e,r,v):
    energies = [0]*len(v)
    leftover = [0]*len(v)
    for i in sorted(v,reverse=True):
        for ind in all_indices(v,i):
            bigger = -1
            smaller = -1
            for j in range(ind+1,len(v)):
                if energies[j]>0:
                    bigger = j
                    break
            for j in range(ind-1,-1,-1):
                if energies[j]>0:
                    smaller = j
                    break
            '''if bigger == smaller == -1:
                energies[ind] = e
                leftover[ind] = 0
            elif smaller == -1:
                energies[ind] = e
                if energies[bigger] > (bigger-ind)*r:
                    energies[ind] = (bigger-ind)*r
                leftover[ind] = e - energies[ind]
            elif bigger == -1:
                energies[ind] = min(e,(ind-smaller)*r)
                leftover[ind] = 0
            else:'''
            available = e
            if smaller != -1:
                available = min(e,leftover[smaller]+(ind-smaller)*r)
            required_leftover = 0
            if bigger != -1:
                required_leftover = max(0,leftover[bigger]+energies[bigger] - (bigger-ind)*r)
            energies[ind] = available - required_leftover
            leftover[ind] = required_leftover
            #print i,smaller,bigger,available,required_leftover
    #print v,energies,leftover
    return sum(map(mul,v,energies))
    
def all_indices(nums,n):
    inds = []
    for i in range(len(nums)):
        if nums[i] == n: inds.append(i)
    return inds

f = open('B-small-attempt4.in')
r = f.readlines()
nums = [map(int,i.split(' ')) for i in r]
w = open('B-small-attempt4.out','w')
for i in range(1,len(nums)/2+1):
    #print problem(nums[2*i-1][0],nums[2*i-1][1],nums[2*i])
    w.write('Case #%s: %d\n' % (i, problem(nums[2*i-1][0],nums[2*i-1][1],nums[2*i])))
f.close()
w.close()
