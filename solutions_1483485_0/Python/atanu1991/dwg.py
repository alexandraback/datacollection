mapping={
        'a' : 'y',
        ' ' : ' ',
        'b' : 'h',
        'c' : 'e',
        'd' : 's',
        'e' : 'o',
        'f' : 'c',
        'g' : 'v',
        'h' : 'x',
        'i' : 'd',
        'j' : 'u',
        'k' : 'i',
        'l' : 'g',
        'm' : 'l',
        'n' : 'b',
        'o' : 'k',
        'p' : 'r',
        'q' : 'z',
        'r' : 't',
        's' : 'n',
        't' : 'w',
        'u' : 'j',
        'v' : 'p',
        'w' : 'f',
        'x' : 'm',
        'y' : 'a',
        'z' : 'q',
       
    }
def func():
    T=int(raw_input())
    for tc in range (1,T+1):
        k=raw_input()
        s=""
        for c in k:
            s=s+mapping[c]
        print "Case #%d: %s"%(tc,s)
func()
