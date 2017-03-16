T = int(input())

ll = [('Z', 'ZERO', '0'), ('W', 'TWO', '2'), ('U', 'FOUR', '4'), ('X', 'SIX', '6'), ('G', 'EIGHT', '8'), ('O', 'ONE', '1'), ('T', 'THREE', '3'), ('S', 'SEVEN', '7'), ('N', 'NINE', '9'), ('F', 'FIVE', '5')]


for i in range(T):
    S = raw_input()
    result = ''
    
    for c, s, r in ll:
        while c in S:
            result += r
            for cc in s:
                S = S.replace(cc, '', 1)
    print("Case #%d: %s" % (i+1, ''.join(sorted(result))))
