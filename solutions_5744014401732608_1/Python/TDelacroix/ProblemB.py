import numpy as np


#f = open('B-sample.in','r')
#g = open('B-sample.ou','w')

#f = open('B-small-attempt3.in','r')
#g = open('B-small.ou','w')

f = open('B-large.in','r')
g = open('B-large.ou','w')


def inputToList(f):
    n = int(f.readline()[:-1])
    iL = []
    for k in range(n):
        l_k = f.readline()[:-1].split(' ')
        iL += [[int(l_k[0]),int(l_k[1])]]
    return iL


iL = inputToList(f)


k = 0
pat = iL[k]

def MatToString(Mat):
    S = ''
    for i in range(len(Mat)):
        for j in range(len(Mat[i])):
            S += str(Mat[i,j])
        S+= '\n'
    return S



def solution(pat):
    B = pat[0]
    M = pat[1]
    N = 2**(B-2)
    if M > N:
        return 'IMPOSSIBLE\n'
    if M ==1:
        Mat = np.zeros((B,B),dtype=int)
        Mat[0,-1] = 1
        S = MatToString(Mat)
        return 'POSSIBLE\n'+S
    else:
        Mat = np.zeros((B,B),dtype=int)
        BIN = bin(M)[2:]
        Bit_max = len(BIN)-1
        for i in range(B-2-Bit_max,B):
            for j in range(i+1,B):
                Mat[i,j]=1
        for k in range(1,len(BIN)):
            if BIN[k] == '1':
                Mat[0,B-Bit_max+k-2] = 1
            if N <> M:
                Mat[0,B-Bit_max-2] = 1
    S = MatToString(Mat)
    return 'POSSIBLE\n'+S






def outputList(iL):
    oL = []
    for k in range(len(iL)):
        oL += [solution(iL[k])]
	print k+1,'Done'
    return oL


oL = outputList(iL)


def outputListToString(oL):
    oS = ''
    for k in range(len(oL)):
        oS += 'Case #'+str(k+1)+': '+oL[k]
    return oS


oS = outputListToString(oL)


g.write(oS)


g.close()
