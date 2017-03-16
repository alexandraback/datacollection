import sys

if __name__=='__main__':
    t = int(sys.stdin.readline())
    for i in range(t):
        sys.stdout.write("Case #{}: ".format(i + 1))
        k, l, s = map(int, sys.stdin.readline().split())
        f = [[0 for i in range(l + 1)] for j in range(s + 1)]
        f[0][0] = 1
        dic = {chr(ord('A') + a):0 for a in range(26)}
        keyboard = sys.stdin.readline()
        s_target = sys.stdin.readline()
        s_target = s_target[:-1]
        ans = 0
        possible = True
        for c in s_target:
            if c not in keyboard:
                ans = 0.0
                possible = False
                break
        if possible:
            target = ' ' + s_target
            for c in keyboard:
                if 'A' <= c <= 'Z':
                    dic[c] = dic[c] + 1
            for c in dic:
                dic[c] = float(dic[c]) / k
            for i in range(1, s + 1):
                f[i][0] = 1
                for t in range(1, l + 1):
                    if t > i:
                        continue
                    f[i][t] = f[i - 1][t - 1] * dic[target[t]]
                    #print t, target[t], f[i][t]
            #for r in f:
            #    for i in r:
            #        print i, ' ',
            #    print
            expect = sum([f[i][l] for i in range(s + 1)])

            shift = l
            for i in range(1, l):
                #print i, s_target[i:], s_target[:l - i]
                if s_target[i:] == s_target[:l - i]:
                    shift = i
                    break
            #print shift
            num = (s - l) / shift + 1
            ans = num - expect
        sys.stdout.write("{}\n".format(ans))

