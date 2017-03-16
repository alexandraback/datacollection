def minm(r,c,w):
    d = c%w
    if d==0:
        ans=r*(c//w) + (w-1)
    else:
        ans=r*(c//w) + w
    return(ans)
        
