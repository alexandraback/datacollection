for t in range(1, int(input())+1):
    s = raw_input()
    freq = {c:0 for c in 'QWERTYUIOPASDFGHJKLZXCVBNM'}
    ans = []
    for c in s:
        if c in freq:
            freq[c] += 1
        else:
            freq[c] = 0
    while freq['Z']:
        freq['Z'] -= 1
        freq['E'] -= 1
        freq['R'] -= 1
        freq['O'] -= 1
        ans += ['0']
    while freq['W']:
        freq['T'] -= 1
        freq['W'] -= 1
        freq['O'] -= 1
        ans += ['2']
    while freq['X']:
        freq['S'] -= 1
        freq['I'] -= 1
        freq['X'] -= 1
        ans += ['6']
    while freq['S']:
        freq['S'] -= 1
        freq['E'] -= 2
        freq['V'] -= 1
        freq['N'] -= 1
        ans += ['7']
    while freq['G']:
        freq['E'] -= 1
        freq['I'] -= 1
        freq['G'] -= 1
        freq['H'] -= 1
        freq['T'] -= 1
        ans += ['8']
    while freq['U']:
        freq['F'] -= 1
        freq['O'] -= 1
        freq['U'] -= 1
        freq['R'] -= 1
        ans += ['4']
    while freq['F']:
        freq['F'] -= 1
        freq['I'] -= 1
        freq['V'] -= 1
        freq['E'] -= 1
        ans += ['5']
    while freq['O']:
        freq['O'] -= 1
        freq['N'] -= 1
        freq['E'] -= 1
        ans += ['1']
    while freq['N']:
        freq['N'] -= 2
        freq['I'] -= 1
        freq['E'] -= 1
        ans += ['9']
    ans += ['3']*freq['T']
    
    print "Case #%d: " % t + ''.join(sorted(ans))
