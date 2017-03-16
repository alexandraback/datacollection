with open('D-large.in', 'r') as file_in:
    lines = file_in.readlines()

t = int(lines[0])
with open('D-large.out', 'w') as file_out:
    for case in range(1, t + 1):
        k, c, s = map(int, lines[case].strip().split())
        if k == 1:
            result  = [1]
        elif c > 1:
            # need floor (k + 1)/2 checks to verify, as one final tile can check for two neighbouring original tiles
            # (if either tile i or i + 1 is gold, then the (i + 1)th tile in i's "section" is gold
            if s >= (k + 1) / 2:
                result = [i * (k ** (c - 1)) + i + 2 for i in range(0, k - 1, 2)]
                # if k is odd the last tile won't be paired so just check the very last tile in the fractal
                if k % 2 == 1:
                    result.append(k ** c)
            else:
                result = ['IMPOSSIBLE']
        elif s == k:
            result = [i + 1 for i in range(k)]
        else:
            result = ['IMPOSSIBLE']
        print('Case #{}: {} (kcs = {} {} {})'.format(case, ' '.join(str(r) for r in result), k, c, s))
        file_out.write('Case #{}: {}\n'.format(case, ' '.join(str(r) for r in result)))