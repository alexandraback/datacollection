import sys


f_input=open(sys.argv[1])
#f_input=open("test.txt")
testcases=int(f_input.readline().rstrip())
for caseNr in xrange(1, testcases+1):
    m_num={}
    n=f_input.readline().rstrip()
    for i in range(int(n)*2-1):
        line=f_input.readline().rstrip()
        fields=line.split()
        for j in range(len(fields)):
            if m_num.has_key(fields[j])==False:
                m_num[fields[j]]=1
            else:
                m_num[fields[j]]=m_num[fields[j]]+1

    missing=[]
    for key in m_num:
        if m_num[key]%2!=0:
            missing.append(int(key))
    missing.sort()
    str1=" ".join(str(x) for x in missing)

    print("Case #%s: %s" % (caseNr, str1))

f_input.close()


