def lastword(w):
    word = w[0]
    for i in range(1,len(w)):
        if ord(w[i])>=ord(word[0]):
            word = w[i]+word
        else: 
            word = word + w[i]
        #print word,
    return word

f = open('input.txt', 'r')
T = int(f.readline())
tcs = []

for i in range(T):
    tcs.append(str(f.readline()))

f.close()
f = open('output.txt', 'w')
for i in range(T):
    f.write("Case #%s: %s" % (i+1, lastword(tcs[i])))
f.close()


