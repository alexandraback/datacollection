import itertools
import collections

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T + 1):
        K, L, S = map(int, raw_input().split())
        keyboard = raw_input()
        target_word = raw_input()
        counter = collections.Counter(keyboard)
        ret = 0
        mx = 0
        for l in itertools.product(set(keyboard), repeat=S):
            s = ''.join(l)
            cnt = 0
            for i in xrange(S):
                if s[i:i + L] == target_word:
                    cnt += 1
            expect = 1.0
            for i in xrange(S):
                expect *= counter[s[i]] * 1.0 / K
            mx = max(mx, cnt)
            ret += cnt * expect
            pass
        print "Case #%d: %.7f" % (t, mx - ret)