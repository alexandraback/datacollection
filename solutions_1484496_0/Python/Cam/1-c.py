from copy import copy
with open('in.txt') as f:
    lines = f.readlines()
    for line, i in zip(lines, range(1, len(lines) + 1)):
        nums = [long(x) for x in line.split()[1:]]
        sums = {}
        for num in nums:
            sums[num] = set([num])
        
        def _pass():
            goAgain = False
            for num in nums:
                original_sums = copy(sums)
                for sum in original_sums:
                    if num in sums[sum]:
                        continue
                    new_sum = sum + num
                    if new_sum not in sums:
                        goAgain = True
                        sums[new_sum] = sums[sum].union(set([num]))
                    elif num not in sums[new_sum]:
                        return (sums[new_sum], sums[sum].union(set([num])))
            
            if goAgain:
                return _pass()
            else:
                return False
        
        result = _pass()
        print "Case #" + str(i) + ":"
        if result:
            for nums in result:
                print (' '.join([str(n) for n in nums])).lstrip()
        else:
            print "Impossible"