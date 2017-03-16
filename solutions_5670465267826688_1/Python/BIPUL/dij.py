table = {
    '1':{
        '1':'1',
        'i':'i',
        'j':'j',
        'k':'k'
        },
    'i':{
        '1':'i',
        'i':'1',
        'j':'k',
        'k':'j'
        },
    'j':{
        '1':'j',
        'i':'k',
        'j':'1',
        'k':'i'
        },
    'k':{
        '1':'k',
        'i':'j',
        'j':'i',
        'k':'1'
        }
    }
minus = {
    '1':{
        '1':False,
        'i':False,
        'j':False,
        'k':False
        },
    'i':{
        '1':False,
        'i':True,
        'j':False,
        'k':True
        },
    'j':{
        '1':False,
        'i':True,
        'j':True,
        'k':False
        },
    'k':{
        '1':False,
        'i':False,
        'j':True,
        'k':True
        }
    }
stage = ['i','j','k','l']
stageMagn = ['1','i','k','1']
stageSign = [False,False,False,True]
def vars(string):
    count = 0
    if 'i' in string: count+=1
    if 'j' in string: count+=1
    if count==2 or 'k' in string: return True
    return False

def solve(string,L,X):
    if not vars(string): return "NO"
    sol,sign,state,i,si,tSign,tMagn = '1',False,0,0,0,None,None
    while i < X:
        si=0
        while si<L:
            s = string[si]
            sign = sign ^ minus[sol][s]
            sol = table[sol][s]
            if (not sign) and sol==stage[state]:
                sol = '1'
                state+=1
            si+=1
        if state ==0 and (not sign) and sol=='1':
            return "NO"
        if i==0:
            tMagn = table[stageMagn[state]][sol]
            tSign = stageSign[state] ^ sign ^ minus[stageMagn[state]][sol]
        i+=1
        if state == 3: break
    leftIter = X-i
    for i in range(leftIter%4):
        sign = sign ^ tSign ^ minus[sol][tMagn]
        sol = table[sol][tMagn]
    #print(state,sol,sign)
    if state==3 and sign==False and sol=='1':
        return "YES"
    else:
        return "NO"
for t in range(int(input())):
    (L,X) = [int(s) for s in input().strip().split(" ")]
    string = input()
    print("Case #{0}: {1}".format(t+1,solve(string,L,X)))
