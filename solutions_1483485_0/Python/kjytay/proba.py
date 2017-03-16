dec = {'y':'a','n':'b','f':'c','i':'d','c':'e','w':'f','l':'g','b':'h',
       'k':'i','u':'j','o':'k','m':'l','x':'m','s':'n','e':'o','v':'p',
       'z':'q','p':'r','d':'s','r':'t','j':'u','g':'v','t':'w','h':'x',
       'a':'y','q':'z', " ":" ", "\n":""}


f = open("A-small-attempt1.in", "r")

N = int(f.readline())
k = 0
googlerese_str = []
while k < N:
    googlerese_str.append(f.readline())
    k += 1

k = 0
while k < N:
    temp = []
    lst = list(googlerese_str[k])
    for char in lst:
        temp.append(dec[char])
    print "Case #" + str(k+1) + ": " + "".join(temp)
    k += 1

