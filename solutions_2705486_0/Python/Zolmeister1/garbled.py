fin = open('garbled.in')
cases = int(fin.readline())
fout = open('garbled.out','w')

dictionary = open("garbled_email_dictionary.txt").read().strip().split("\n")

def pp(case, out):
    ss= "Case #%d: %s\n" % (case+1, out)
    print ss,
    fout.write(ss)

    
def isvalid(word, s):
    lastIndex = -100
    sub = s[:len(word)]
    for i,let in enumerate(sub):
        if sub[i]!=word[i]:
            if lastIndex-i>=5:
                return False
            lastIndex=i
    return True
    
def errors(word,s):
    cnt=0
    sub = s[:len(word)]
    for i,let in enumerate(sub):
        if sub[i]!=word[i]:
            cnt+=1
    return cnt

def info(word,s,wordlen):
    cnt=0
    lastIndex = -100
    sub = s[:wordlen]
    for i,let in enumerate(sub):
        if sub[i]!=word[i]:
            cnt+=1
            if i-lastIndex<5:
                return -1
            lastIndex=i
    return cnt

for case in xrange(cases):
    cnt = 0
    s = fin.readline().strip()
    #print s
    while s:
        biggest = ""
        errorCnt = 9999999
        biglen = 0
        for word in dictionary:
            wordlen = len(word)
            if wordlen <= len(s):
                errs = info(word,s,wordlen)
                if errs == -1:
                    continue
                if errs == errorCnt and wordlen>biglen:
                    biggest = word
                    biglen = wordlen
                    errorCnt = errs
                elif errs<errorCnt:
                    biggest = word
                    errorCnt = errs
                    biglen = wordlen
        #print biggest, errorCnt
        cnt+=errorCnt
        s = s[biglen:]
        #print s
    pp(case,cnt)
    #loop
    #find longest dictionary word that matches the most letters and is valid(index count) and has least error letters
    #work backwards, so start at the end
    #remove those letters from the current set, and add the error letter count to cnt
    