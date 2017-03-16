t = int(input())

def same(i, s, l):
    _s = str(i).zfill(l)
    for j in range(l):
        if s[j] is not '?' and s[j] != _s[j]:
            return False
    return True


for z in range(t):
    a, b = raw_input().split(' ')
    l = len(a)
    mini = pow(10, l)
    large = mini
    res_i = 0
    res_j = 0
    for i in range(large):
        if not same(i, a, l):
            continue
        for j in range(large):
            if same(j, b, l):
                diff = abs(i - j)
                if diff < mini:
                    mini = diff
                    res_i = i
                    res_j = j
    
    print "Case #{}: {} {}".format(z + 1, str(res_i).zfill(l), str(res_j).zfill(l))
