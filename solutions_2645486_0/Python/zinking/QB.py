import sys

def manage_energy( ti, E, R, nac, ac ):
    vv = [ R for ii in range(0,nac)];
    if E > R :
        maxindex = -1;
        maxvalue = -1;
        for iii in range( 0,nac ):
            if ac[iii] > maxvalue:
                maxvalue = ac[iii];
                maxindex = iii;
                #print '[DEBUG LOOP]', iii, maxvalue, ac[iii]
        vv[maxindex] = E
    elif  E < R :
        vv[0] = E
    #print '[DEBUG]'
    #print ti,E,R,nac,ac
    #print ac
    #print vv
    #print '[DEBUG]'
    result = 0
    for  ii in range( 0, nac ):
        result += ac[ii]*vv[ii];
        
    print 'Case #%d: %d'%(ti,result)

   
if __name__=="__main__":
    
    n = int( sys.stdin.readline() )
    for i in range(0,n):
        l1 = sys.stdin.readline()
        l1l = l1.split( );
        l2 = sys.stdin.readline()
        l2l = l2.split( );
        l2ll = map( lambda x:int(x), l2l )
        manage_energy( i+1, int(l1l[0]), int(l1l[1]), int(l1l[2]), l2ll );