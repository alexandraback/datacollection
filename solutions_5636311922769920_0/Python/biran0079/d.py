T = int(raw_input())
for i in range(T):
    K,C,S = map(int, raw_input().split())
    print "Case #{}: {}".format(i+1, " ".join(map(str, range(1, S + 1))))
