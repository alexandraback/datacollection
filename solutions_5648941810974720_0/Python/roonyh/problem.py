fo = open("sm.in", "r")

T = int(fo.readline())

for zz in range(T):
    w = fo.readline()

    nums = {}

    nums[0] = w.count('Z')
    nums[2] = w.count('W')
    nums[4] = w.count('U')
    nums[5] = w.count('F') - nums[4]
    nums[6] = w.count('X')
    nums[7] = w.count('S') - nums[6]
    nums[8] = w.count('G')
    nums[3] = w.count('H') - nums[8]
    nums[9] = w.count('I') - nums[8] - nums[6] - nums[5]
    nums[1] = w.count('O') - nums[0] - nums[2] - nums[4]

    s = ""
    for a in nums:
        s += str(a) * nums[a]

    print "Case #%d: %s" % (zz+1, s)