from collections import Counter

with open('A-large.in', 'r') as f, open('a.out', 'w') as g:
    tests = None
    n = 0
    for line in f:
        line = line.rstrip()
        if tests is None:
            tests = int(line)
            continue
        n += 1
        digits = Counter()
        chars = Counter(line)
        print(n, line)
        k = 0
        while sum(chars.values()) > 0:
            if chars['Z'] > 0:
                digits[0] += 1
                for ch in 'ZERO':
                    chars[ch] -= 1
                continue
            if chars['W'] > 0:
                digits[2] += 1
                for ch in 'TWO':
                    chars[ch] -= 1
                continue
            if chars['U'] > 0:
                digits[4] += 1
                for ch in 'FOUR':
                    chars[ch] -= 1
                continue
            if chars['F'] > 0:
                digits[5] += 1
                for ch in 'FIVE':
                    chars[ch] -= 1
                continue
            if chars['X'] > 0:
                digits[6] += 1
                for ch in 'SIX':
                    chars[ch] -= 1
                continue
            if chars['V'] > 0:
                digits[7] += 1
                for ch in 'SEVEN':
                    chars[ch] -= 1
                continue
            if chars['G'] > 0:
                digits[8] += 1
                for ch in 'EIGHT':
                    chars[ch] -= 1
                continue
            if chars['I'] > 0:
                digits[9] += 1
                for ch in 'NINE':
                    chars[ch] -= 1
                continue
            if chars['O'] > 0:
                digits[1] += 1
                for ch in 'ONE':
                    chars[ch] -= 1
            if chars['H'] > 0:
                digits[3] += 1
                for ch in 'THREE':
                    chars[ch] -= 1
                continue
        ans = ''
        for i in range(10):
            ans += str(i) * digits[i]
        print(ans)
        g.write('Case #' + str(n) + ': ' + ans + '\n')



