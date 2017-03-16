f=open("speaking.txt","r")
lists=f.readlines()
tests=int(lists[0])
i=1
words={
    'y':'a',
    'n':'b',
    'f':'c',
    'i':'d',
    'c':'e',
    'w':'f',
    'l':'g',
    'b':'h',
    'k':'i',
    'u':'j',
    'o':'k',
    'm':'l',
    'x':'m',
    's':'n',
    'e':'o',
    'v':'p',
    'z':'q',
    'p':'r',
    'd':'s',
    'r':'t',
    'j':'u',
    'g':'v',
    't':'w',
    'h':'x',
    'a':'y',
    'q':'z',
    }
while i<=tests:
    string=lists[i]
    newstr=[]
    for ch in string:
        if ch=='\n':
            continue        
        if ord(ch)>96 and ord(ch)<123:
            newstr.append(words[ch])
        else:
            newstr.append(ch)
    
    print "Case #%d: %s" %(i,''.join(newstr))
    i=i+1
