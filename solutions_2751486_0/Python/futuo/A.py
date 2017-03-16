
def countNValue( string, target):

    count = 0
    for i in string:
        if( i in "aeiou" ):
            count = 0
        else:
            count += 1
            if( count == target ):
                return True

    return False

ntt = int( raw_input() )

for tt in range( 1,ntt+1 ):

    aux = raw_input()
    aux = aux.split(" ")

    name = aux[0]
    target = int( aux[1] )
    count = 0

    for i in range( 0, len(name) ):
        for j in range( i+1, len(name)+1 ):
            if( countNValue( name[i:j], target ) ):
                count+=1

    print "Case #"+str(tt)+":", count

