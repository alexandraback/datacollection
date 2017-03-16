def special(freq, sp, other):
    sind = ord(sp) - ord('A')
    x = freq[sind]
    for c in other:
        freq[ord(c) - ord('A')] -= x
    freq[sind] = 0
    return x

def fmt(ans):
    ret = ""
    for i, e in enumerate(ans):
        base = str(i)
        ret += base * e

    return ret

def main():
    T = int(input())
    for case_num in range(1, T + 1):
        s = input()
        freq = [0] * 26
        for c in s:
            index = ord(c) - ord('A')
            freq[index] += 1
        # check for zero
        ans = [0] * 10
        ans[0] = special(freq, 'Z', 'ERO')
        # check for two
        ans[2] = special(freq, 'W', 'TO')
        # check for four
        ans[4] = special(freq, 'U', 'FOR')
        # check for six
        ans[6] = special(freq, 'X', 'SI')
        # check for eight
        ans[8] = special(freq, 'G', 'EIHT')

        # remaining numbers are ONE NINE
        ans[5] = special(freq, 'F', 'IVE')
        ans[7] = special(freq, 'V', 'SEEN')
        ans[3] = special(freq, 'H', 'TREE')
        ans[9] = special(freq, 'I', 'NNE')
        ans[1] = special(freq, 'O', 'NE')

        print("Case #{0}: {1}".format(case_num, fmt(ans)))

main()
