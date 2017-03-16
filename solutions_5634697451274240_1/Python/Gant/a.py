def swap(s, idx):
    return flip(s[idx::-1]) + s[idx+1:]

def flip(s):
    result = ''
    for c in s:
        if c == '+':
            result += '-'
        else:
            result += '+'
    return result

def abc(s):
    num_swaps = 0

    while True:
        if s[0] == '+':
            idx = s.find('-')
            if idx != -1:
                num_swaps += 1
                s = swap(s, idx - 1)
            else:
                return num_swaps
        else:
            idx = s.rfind('-')
            num_swaps += 1
            s = swap(s, idx)


if __name__ == '__main__':
    import sys
    with open(sys.argv[1]) as f:
        T = int(f.readline());
        for t in range(T):
            s = f.readline();
            print "Case #{}: {}".format(t+1, abc(s))
