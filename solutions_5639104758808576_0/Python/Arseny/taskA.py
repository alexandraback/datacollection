
def solve(s_all):
    friends = 0
    standing = 0
    for level, num in enumerate(s_all):
        if standing < level:
            friends+= (level - standing)
            standing = level
        standing+= num
    return friends


if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        s_max, s_all = raw_input().split()
        s_max = int(s_max)
        s_all = map(int, s_all)
        print "Case #{0}:".format(t + 1), solve(s_all)
