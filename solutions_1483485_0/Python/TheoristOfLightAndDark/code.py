f = open("in.txt","r")
g = open("out.txt","w")
map = {
'a':'y',
'b':'h',
'c':'e',
'd':'s',
'e':'o',
'f':'c',
'g':'v',
'h':'x',
'i':'d',
'j':'u',
'k':'i',
'l':'g',
'm':'l',
'n':'b',
'o':'k',
'p':'r',
'q':'z',
'r':'t',
's':'n',
't':'w',
'u':'j',
'v':'p',
'w':'f',
'x':'m',
'y':'a',
'z':'q',
' ':' '
}
for t in range(1,int(f.readline())+1):
    st = f.readline().strip("\n")
    l = []
    for ch in st:
        l.append(map[ch])
    g.write("Case #"+str(t)+": "+"".join(l)+"\n")
f.close()
g.close()