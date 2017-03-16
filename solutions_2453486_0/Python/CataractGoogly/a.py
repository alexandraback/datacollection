def four_in_a_row(g, r, c, dr, dc, p):
    for i in range(4):
        if g[r][c] != p and g[r][c] != 'T':
            return False
        r += dr
        c += dc
    return True

def solve():
    g = []
    for i in range(4):
        g.append(raw_input())
    for p in 'XO':
        for r in range(4):
            if four_in_a_row(g, r, 0, 0, 1, p):
                return '%s won' % p
            if four_in_a_row(g, 0, r, 1, 0, p):
                return '%s won' % p
        if four_in_a_row(g, 0, 0, 1, 1, p):
            return '%s won' % p
        if four_in_a_row(g, 0, 3, 1, -1, p):
            return '%s won' % p
    for i in range(4):
        if '.' in g[i]:
            return 'Game has not completed'
    return 'Draw'

def main():
    T = int(raw_input())
    for t in range(T):
        print 'Case #%d: %s' % (t+1, solve())
        raw_input()

if __name__ == '__main__':
    main()
    