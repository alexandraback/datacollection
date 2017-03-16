in_file = open( "input.txt" )
out_file = open( "output.txt", "w" )

def write( string, _index ):
	out_file.write( "Case #" + _index + ": " + string + "\n" )

cases = int( in_file.readline().strip() )
index = 1

def get_list( cls_dict, node ):
	ret_list = []
	for n in cls_dict[ node ]:
		ret_list.append( n )
		ret_list += get_list( cls_dict, n )
	return ret_list
	
while index <= cases:
	no_classes = int( in_file.readline().strip() )
	cls_dict = {}
	res_dict = {}
	for i in range( 1, no_classes + 1):
		line = in_file.readline().strip().split()
		tmp_no = int( line[ 0 ] )
		line = line[ 1: ]		
		cls_dict[ i ] = []
		res_dict[ i ] = []
		if line:
			for val in line:
				if tmp_no > 0:
					cls_dict[ i ].append( int( val ) )					
	for node in cls_dict:
		res_dict[ node ].append( get_list( cls_dict, node ) )	
	for node in res_dict:
		cls_list = res_dict[ node ][ 0 ]
		cls_list.sort()		
		flag = False
		for i in range( 0, len( cls_list ) - 1 ):
			if cls_list[ i ] == cls_list[ i + 1 ]:
				flag = True
				break
		if flag:
			write( "Yes", str( index ) )
			break
	else:		
		write( "No", str( index ) )
	index += 1
	pass
	
in_file.close()
out_file.close()