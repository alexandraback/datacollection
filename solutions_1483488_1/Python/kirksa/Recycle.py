import sys

def get_all_shifted_variants(number):
    as_string = str(number)
    res = []
    for i in xrange(1,len(as_string)):
        res.append(int(as_string[i:] + as_string[:i]))
    return res
def get_all_pairs(number,min,max):
    variants = get_all_shifted_variants(number)
    pairs = []
    for shifted in variants:
        if shifted == number:
            continue
        if shifted > max or shifted < min:
            continue
        if number > shifted:
            pairs.append(str(shifted) + str(number))
        else:
            pairs.append(str(number) + str(shifted))
    return pairs
def get_pairs_count(min,max):
    pairs_hash = {}
    for i in xrange(min,max):
        pairs = get_all_pairs(i,min,max)
        for x in pairs:
            pairs_hash[x] = 1
    return len(pairs_hash)

lines = file(sys.argv[1]).readlines()
i = 1
while i <= int(lines[0]):
    min,max = lines[i].split(" ")
    print "Case #"+str(i)+": " + str(get_pairs_count(int(min),int(max)))
    i+=1