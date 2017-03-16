def isPalindromic(k):
    return str(k) == str(k)[::-1]
sqrt = 10 ** 7
nums = [k * k for k in xrange(1, sqrt + 1) if isPalindromic(k) and isPalindromic(k * k)]
largeststate = 2 * len(nums) + 7
pow = 1
exponent = 0
while pow <= largeststate:
    pow *= 2
    exponent += 1
mask = pow - 1
print """state = 0
for x in [int(z) for z in open("C-large-1.in").read().split()]:
    if state == 0:
        state = 1
    elif (state & %d) == 1:
        if x == 1:
            state += %d""" % (mask, len(nums) + 1)
for i in xrange(1,len(nums)):
    print """        elif x <= %d:
            state += %d""" % (nums[i], len(nums) + 1 - i)
print """        else:
            state += 1
    elif (state & %d) in range(2, %d):""" % (mask, len(nums) + 3)
for i in xrange(len(nums)-1,0,-1):
    print """        %sif x >= %d:
            state += %d""" % ("el" if i < len(nums) - 1 else "", nums[i], i + len(nums) + 1)
print """        else:
            state += %d
    if (state & %d) >= %d:
        print "Case #%%d: %%d" %% ((state >> %d) + 1, (state & %d) - %d)
        state = %d + (state & -%d)""" % (len(nums)+1, mask, len(nums)+3, exponent, mask, 2*len(nums)+2, pow + 1, pow)
