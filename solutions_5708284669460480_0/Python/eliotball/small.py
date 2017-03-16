import sys

def perms(keys, count):
    if count == 0:
        yield ""
    else:
        for sub_perm in perms(keys, count - 1):
            for key in keys:
                yield key + sub_perm

def count_instances(keys, target, count):
    counts = {i: 0 for i in xrange(0, count+1)}
    for perm in perms(keys, count):
        target_count = count_target(perm, target)
        counts[target_count] += 1
    init_bananas = 0
    total_perms = 0
    for i in xrange(count+1):
        if counts[i] > 0:
            init_bananas = i
            total_perms += counts[i]
    expect = 0
    for i in xrange(count):
        expect += (init_bananas - i) * (float(counts[i]) / total_perms)
    return expect

def count_target(perm, target):
    count = 0
    for pos in xrange(len(perm) - len(target) + 1):
        if perm[pos:pos+len(target)] == target:
            count += 1
    return count

if __name__ == "__main__":
    case_count = int(raw_input())
    for case_num in xrange(1, case_count + 1):
        _, _, count = [int(i) for i in raw_input().split()]
        keys = raw_input()
        target = raw_input()
        print "Case #%s: %s" % (case_num, count_instances(keys, target, count))
        sys.out.flush()
