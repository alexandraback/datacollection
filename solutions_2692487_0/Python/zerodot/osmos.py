

def turns(size,motes,ops=0):
    if size==0 or ops>100:
        return 101
    #biggest
    elif len(motes)==0:
        return ops
    #absorb
    elif size>motes[-1]:
        return turns(size+motes[-1],motes[:-1],ops)
    else:
        #remove or add
        removed=ops+len(motes)
        added=turns(size, motes+[size-1],ops+1)
        return min(removed,added)

if __name__=='__main__':
    cases=int(input())
    for i in range(cases):
        [armin,n_motes]=[int(e) for e in input().split()]
        motes=[int(e) for e in input().split()]
        motes.sort(reverse=True)
        ans=turns(armin,motes)
        print("Case #"+str(i+1)+": "+str(ans))
