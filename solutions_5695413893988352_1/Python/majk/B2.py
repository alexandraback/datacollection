
def findeq(C,J):
    L=len(C)
    S=''
    for i in range(L):
        if C[i] == '?' and J[i] == '?':
            S += '0'
        elif C[i] == '?':
            S += J[i]
        elif J[i] == '?':
            S += C[i]
        elif C[i] == J[i]:
            S += C[i]
        else:
            break
    return S

def best(C,J):
    S=findeq(C,J)
    L=len(C)
    if len(S) == len(C):
        return S,S

    first=-1
    for i in range(L):
        if C[i] != '?' and J[i] != '?':
            first = i
            break

    if first == -1:
        return C,J

    B,MC,MJ=10**10,10**10,10**10
    if C[first] == J[first]:
        NC,NJ=best(C[first+1:],J[first+1:])
        NC = C[first] + NC
        NJ = J[first] + NJ
        if first > 0:
            for PC,PJ in findlower(C[:first],J[:first]):
                IC=int(PC+NC)
                IJ=int(PJ+NJ)
                B,MC,MJ=min((B,MC,MJ),(abs(IC-IJ),IC,IJ))
            for PC,PJ in findlower(C[:first],J[:first]):
                IC=int(PC+NC)
                IJ=int(PJ+NJ)
                B,MC,MJ=min((B,MC,MJ),(abs(IC-IJ),IC,IJ))
            P=findeq(C[:first],J[:first])
            if len(P) == first:
                IC=int(P+NC)
                IJ=int(P+NJ)
                B,MC,MJ=min((B,MC,MJ),(abs(IC-IJ),IC,IJ))

        else:
            IC=int(NC)
            IJ=int(NJ)
            B,MC,MJ=min((B,MC,MJ),(abs(IC-IJ),IC,IJ))

    P=findeq(C[:first],J[:first])
    if len(P) == first:
        NC=C[first:].replace('?','9')
        NJ=J[first:].replace('?','0')
        IC=int(P+NC)
        IJ=int(P+NJ)
        B,MC,MJ=min((B,MC,MJ),(abs(IC-IJ),IC,IJ))

        NC=C[first:].replace('?','0')
        NJ=J[first:].replace('?','9')
        IC=int(P+NC)
        IJ=int(P+NJ)
        B,MC,MJ=min((B,MC,MJ),(abs(IC-IJ),IC,IJ))

    for PC,PJ in findlower(C[:first],J[:first]):
        NC=C[first:].replace('?','9')
        NJ=J[first:].replace('?','0')
        IC=int(PC+NC)
        IJ=int(PJ+NJ)
        B,MC,MJ=min((B,MC,MJ),(abs(IC-IJ),IC,IJ))

    for PJ,PC in findlower(J[:first],C[:first]):
        NC=C[first:].replace('?','0')
        NJ=J[first:].replace('?','9')
        IC=int(PC+NC)
        IJ=int(PJ+NJ)
        #assert IJ > IC
        B,MC,MJ=min((B,MC,MJ),(abs(IC-IJ),IC,IJ))

    return str(MC).zfill(len(C)),str(MJ).zfill(len(C))


def findlower(C,J):
    if len(C) == 0:
        yield '',''
    for i in range(len(C)):
        FC,FJ=findlowerin(C,J,i)
        if FC != '':
            yield FC,FJ

def findlowerin(C,J,I):
    L=len(C)
    RC,RJ='',''
    O=False
    for i in range(L-1,-1,-1):
        if O:
            if C[i] == '?' and J[i] == '?':
                RC += '0'
                RJ += '0'
            elif C[i] == '?':
                RC += J[i]
                RJ += J[i]
            elif J[i] == '?':
                RC += C[i]
                RJ += C[i]
            else:
                assert False
        elif J[i] == '0':
            RJ += '0'
            RC += '9'
        elif J[i] != '?':
            if I == i:
                RJ += J[i]
                RC += str(int(J[i])-1)
                O = True
            else:
                RJ += J[i]
                RC += J[i]
        elif C[i] == '?':
            if I == i:
                RJ += '1'
                RC += '0'
                O = True
            else:
                RJ += '0'
                RC += '9'
        elif C[i] == '9':
            RJ += '0'
            RC += '9'
        elif I == i:
            RJ += str(int(C[i]) +1)
            RC += C[i]
            O = True
        else:
            RJ += C[i]
            RC += C[i]
        if I == i and not O:
            return '',''
    return RC[::-1],RJ[::-1]




T=int(input())
for t in range(T):
    C,J=input().split()
    BC,BJ=best(C,J)
    print("Case #%d: %s %s" % (t+1, BC, BJ))

