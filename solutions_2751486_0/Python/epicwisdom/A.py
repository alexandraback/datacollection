def main():
    vowels = set('aeiou')
    name = 'A-small-attempt0'
    lines = open(name+'.in').readlines()
    T = int(lines[0])
    s = ''
    for line in range(1,T+1):
        case = 'Case #'+str(line)+': '
        s2, n = lines[line].split()
        n = int(n)
        count = 0
        valid = 0
        left = 0
        i = 0
        for k,c in enumerate(s2):
            if c not in vowels:
                if count == 0:
                    i = k
                count += 1
            else:
                count = 0
            if count >= n:
                valid += (i - left + 1) * (len(s2) - k)
                left = i + 1
                i += 1
        case += str(valid)
        s += case + '\n'
    open(name+'.out', 'w').write(s)

if __name__ == '__main__':
    main()
