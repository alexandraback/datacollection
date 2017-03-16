
global coder, jammer
global ALL_RES


def testcase(ind): # Getting the Digits --> very cleaver method 
    global coder, jammer,ALL_RES
    ALL_RES = []
    coder, jammer = raw_input().split()
    mingap, minc, minj = None, None, None
    bestc, bestj = None, None
    dfs('', '', None)
    for (resc, resj) in ALL_RES:
        c,j = int(resc), int(resj)
        gap = abs(c-j)
        if mingap==None or gap<mingap: 
            mingap, minc, minj = gap, c, j
            bestc, bestj = resc, resj
        if gap==mingap and  c<minc: 
            mingap, minc, minj = gap, c, j
            bestc, bestj = resc, resj
        if gap==mingap and c==minc and j<minj: 
            mingap, minc, minj = gap, c, j
            bestc, bestj = resc, resj
    print 'Case #%d: %s %s' % (ind, bestc, bestj)


def dfs(resc, resj, clarger):
    #~ print resc, resj, clarger
    for i in xrange(len(resc), len(coder)):
        c, j = coder[i], jammer[i]
        if c!='?' and j!='?': # none of them is '?'
            if c==j:
                resc += c; resj += j
            if c!=j:
                if clarger==None: # if haven't decided which is larger
                    clarger = ( int(c)>int(j) )
                resc += c; resj += j
        elif c==j and c=='?': # all of them are ?
            if clarger==None:
                dfs(resc+'0', resj+'0', None)
                dfs(resc+'1', resj+'0', True)
                dfs(resc+'0', resj+'1', False)
                return 
                
            elif clarger:
                resc += '0'; resj += '9'
            else:
                resc += '9'; resj += '0'
        else: # if only one of them is '?'
            if clarger!=None: # if relative order is already defined
                if j=='?' and clarger: resc+=c; resj+='9'
                elif j=='?' and clarger==False: resc+=c; resj+='0'
                elif c=='?' and clarger: resc+='0'; resj+=j
                elif c=='?' and clarger==False: resc+='9'; resj+=j
            if clarger==None: # BACKTRACK HERE!!
                d = c if c!='?' else j
                # option 1: equal
                dfs(resc+d, resj+d, clarger)
                # option 2: larger or smaller
                if d!='9': 
                    d1 = str(int(d)+1)
                    if j=='?': 
                        dfs(resc+c, resj+d1, False)
                    elif c=='?':
                        dfs(resc+d1, resj+j, True)
                if d!='0':
                    d1 = str(int(d)-1)
                    if j=='?': 
                        dfs(resc+c, resj+d1, True)
                    elif c=='?':
                        dfs(resc+d1, resj+j, False)
                return 
    # end for   
    ALL_RES.append( (resc, resj) )


if __name__=='__main__':
    T = int(raw_input())
    for i in xrange(T):
        testcase(i+1)
