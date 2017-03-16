import sys
import string

# Arguments: [in] [out]
# Defaults: in='input.txt', out=stdout

# P_t0 = list of P(t0=this)
#           t0 = number of chars of tgt already typed
# returns avg * len(tgt) = avg bananas assuming 
#   inx chars typed before this func
def avg_fromhere(keyb, tgt, sh, cnt):
    
    # End recursion
    if cnt == 0: return [0.0] * len(tgt) 
    assert cnt > 0
    
    # Get result from next level
    contAvgB = avg_fromhere(keyb, tgt, sh, cnt-1)
    
    res = []
    for t0 in range(len(tgt)):
        # assume first t0 chars of tgt already typed
        B = 0.0
        for k in keyb:
            if k == tgt[t0]:
                if t0+1 == len(tgt): 
                    B+= 1 + contAvgB[t0+1 - sh]
                else:
                    B += contAvgB[t0+1]
            elif t0==0:
                B += contAvgB[0]
            else:
                # find next t0 values
                so_far = tgt[:t0] + k
                s = 1
                while s < t0:
                    if so_far[s:] == tgt[:t0+1-s]:
                        break
                    s += 1
                assert t0-s >= 0
                B += contAvgB[t0-s]
        res.append(B/len(keyb))
    print "cnt=",cnt,"sh=",sh," avgBs=",res
    return res
    
def bananas(kb,tgt,cnt):
    assert cnt >= len(tgt)

    # Check if all target chars can be typed
    for t in tgt:
        if t not in kb:
            return 0.0
    
    sh = 1
    while sh < len(tgt):
        if tgt == tgt[sh:] + tgt[:sh]:
            break
        sh += 1
    mxB = 1 + (cnt - len(tgt)) / sh
    print "max bananas:",mxB
    
    avB = avg_fromhere(kb, tgt, sh, cnt)[0]
    return mxB - avB

if len(sys.argv) > 1:
    input_file = len(sys.argv)>1 and sys.argv[1] or 'input.txt'
    outf = len(sys.argv)>2 and open(sys.argv[2],'w') or sys.stdout
    with open(input_file) as f:
        T = int(f.readline())
        for x in range(T):
            K, L, S = map(int, f.readline().split(' '))
            kb = f.readline().strip()
            tgt = f.readline().strip()
            assert len(kb) == K
            assert len(tgt) == L
            print "keyboard=",kb
            print "target =",tgt
            print "len(tgt)=",len(tgt)," S=",S
            outf.write('Case #{0}: {1}'.format(x+1, bananas(kb,tgt,S)))
            outf.write('\n')
