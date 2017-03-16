def dec(map, letter):
    map[letter] -= 1
    if map[letter] == 0:
        del map[letter]

def solve(l):
    count = {}
    nums = []
    for c in l:
        if c in count:
            count[c] += 1
        else:
            count[c] = 1

    while count:
        if 'Z' in count:
            dec(count, 'Z')
            dec(count, 'E')
            dec(count, 'R')
            dec(count, 'O')
            nums.append(0)
            continue
        if 'W' in count:
            dec(count, 'T')
            dec(count, 'W')
            dec(count, 'O')
            nums.append(2)
            continue
        if 'G' in count:
            dec(count, 'E')
            dec(count, 'I')
            dec(count, 'G')
            dec(count, 'H')
            dec(count, 'T')
            nums.append(8)
            continue
        if 'X' in count:
            dec(count, 'S')
            dec(count, 'I')
            dec(count, 'X')
            nums.append(6)
            continue
        if 'H' in count:
            dec(count, 'T')
            dec(count, 'H')
            dec(count, 'R')
            dec(count, 'E')
            dec(count, 'E')
            nums.append(3)
            continue
        if 'R' in count:
            nums.append(4)
            dec(count, 'F')
            dec(count, 'O')
            dec(count, 'U')
            dec(count, 'R')
            continue
        if 'O' in count:
            dec(count, 'O')
            dec(count, 'N')
            dec(count, 'E')
            nums.append(1)
            continue
        if 'F' in count:
            dec(count, 'F')
            dec(count, 'I')
            dec(count, 'V')
            dec(count, 'E')
            nums.append(5)
            continue
        if 'V' in count:
            dec(count, 'S')
            dec(count, 'E')
            dec(count, 'V')
            dec(count, 'E')
            dec(count, 'N')
            nums.append(7)
            continue
        if 'N' in count:
            dec(count, 'N')
            dec(count, 'I')
            dec(count, 'N')
            dec(count, 'E')
            nums.append(9)
            continue
    return ''.join([str(x) for x in sorted(nums)])



if __name__ == '__main__':
    input = 'A-large.in'
    output = 'A-large.out'

    with open(input) as f:
        content = f.readlines()
    content = [x.strip('\n') for x in content]

    with open(output, 'w') as o:
        for i, l in enumerate(content[1:]):
            o.write('Case #%d: %s' % ((i+1), solve(l)))
            o.write('\n')
