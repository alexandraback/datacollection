def g(S):
    counts = {}
    for c in S:
        if c not in counts:
            counts[c] = 0
        counts[c] += 1

    nc = {}
    words = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    uniq = ['Z', 'O', 'W', 'T', 'U', 'F', 'X', 'S', 'G', 'I']
    uniq_order = ['Z', 'W', 'U', 'X', 'G', 'O', 'F', 'S', 'T', 'I']
    uniq_map = {}
    for i in range(len(uniq)):
        uniq_map[uniq[i]] = i

    for c in uniq_order:
        if c in counts and counts[c] > 0: 
            n = counts[c]
            nc[uniq_map[c]] = n
            for a in words[uniq_map[c]]:
                counts[a] -= n

    ans = ""
    for k in sorted(nc.keys()):
        ans = ans + (str(k)*nc[k])
    return ans


def main():
    T = int(raw_input())
    for t in range(1, T + 1):
        word = raw_input().strip()
        print "Case #{0}: {1}".format(t, g(word))

if __name__ == "__main__":
    main()