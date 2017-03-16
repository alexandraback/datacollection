def flip(seq):
    if (len(seq) == 1):
        if seq[0] == '+':
            return 0
        else:
            return 1
    if seq[0] == '-':
        if seq[-1] == '-':
            return len(seq)
        else:
            return len(seq) - 1
    else:
        if seq[-1] == '-':
            return len(seq)
        else:
            return len(seq) - 1


def simplify(seq):
    seq_simp = []
    seq_simp.append(seq[0])
    for char in seq:
        if char != seq_simp[-1]:
            seq_simp.append(char)
    return seq_simp


def main():
    t = int(input())
    for i in range(t):
        seq = simplify(input())
        print("Case #{}: {}".format(i+1, flip(seq)))


if __name__ == '__main__':
    main()
