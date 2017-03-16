def one(bools):
    for b in bools:
        if b:
            return True
    return False

def guess(prods):
    nums = []
    if 24 in prods:
        return '234'
    if 30 in prods:
        return '235'
    if 40 in prods:
        return '245'
    if 60 in prods:
        return '345'
    if 18 in prods:
        return '233'
    if 27 in prods:
        return '333'
    if 3*3*4 in prods:
        return '334'
    if 3*3*5 in prods:
        return '335'
    if 32 in prods:
        return '442'
    if 4*4*3 in prods:
        return '443'
    if 4*4*5 in prods:
        return '445'
    if 50 in prods:
        return '255'
    if 75 in prods:
        return '355'
    if 100 in prods:
        return '455'
    if 125 in prods:
        return '555'
    if 16 in prods:
        nums.append(4)
        nums.append(4)
    if 9 in prods:
        nums.append(3)
        nums.append(3)
    if 25 in prods:
        nums.append(5)
        nums.append(5)
    if one([0 if p%2 else 1 for p in prods]):
        if 2 not in nums:
            nums.append(2)
    if one([0 if p%3 else 1 for p in prods]):
        if 3 not in nums:
            nums.append(3)
    if one([0 if p%5 else 1 for p in prods]):
        if 5 not in nums:
            nums.append(5)
    if len(nums) == 3:
        return '%i%i%i' % tuple(nums)
    return '225'

def run(filename):
    lines = [line.strip() for line in open(filename).readlines() if line.strip()]
    print 'Case #1:'
    for line in lines[2:]:
        print guess([int(elt) for elt in line.split()])

run('small_input.txt')
