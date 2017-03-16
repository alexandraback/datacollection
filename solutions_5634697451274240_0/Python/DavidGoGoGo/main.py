def count(seq, start):
    if start >= len(seq):
        return 0
    for i in range(start, len(seq)):
        while start + 1 < len(seq) and seq[start] == seq[start + 1]:
            start += 1
        if seq[start] == '+':
            return count(seq, start + 1)
        else:       # == '-'
            if start + 1 == len(seq):
                return 1
            else:
                return count(seq, start + 1) + 2


def main():
    infile = open('input.txt', 'r')
    ofile = open('output.txt', 'w')
    t = int(infile.readline())
    for i in range(1, t+1):
        seq = list(reversed([s for s in infile.readline()[:-1]]))
        res = count(seq, 0)
        print("Case #{}: {}".format(i, res))
        ofile.write("Case #{}: {}\n".format(i, res))
    infile.close()
    ofile.close()

main()