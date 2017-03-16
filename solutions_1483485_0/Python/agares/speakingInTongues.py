translator = {'y':'a','n':'b','f':'c','i':'d','c':'e','w':'f','l':'g','b':'h','k':'i',
'u':'j','o':'k','m':'l','x':'m','s':'n','e':'o','v':'p','z':'q','p':'r',
'd':'s','r':'t','j':'u','g':'v','t':'w','h':'x','a':'y','q':'z', ' ': ' '}

def traducir(texto):
    traducido=""
    for a in texto:
        traducido+=translator[a]
    return traducido

f = open('input.txt', 'r').read().splitlines()
n = int(f[0])
for i in range(1, n+1):
    print "Case #%d: %s" % (i, traducir(f[i]))

