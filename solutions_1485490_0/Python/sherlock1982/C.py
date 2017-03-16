import sys

inp  = sys.stdin
#inp = open( "C.test2", "r")
outp = sys.stdout

T = int( inp.readline() )

total_max = 0

def do_throw( elements, versa ):
    # Nothing left
    if len(elements) == 0 or len(versa) == 0:
        return elements
    for i in range( len(elements)/2 ):
        if elements[ 1 + 2*i ] == versa[1]:
            return elements[ 2*i: ]
    return []

def analyze( boxes, toys ):
    global total_max
    # Nothing left
    if len(boxes) == 0 or len(toys) == 0:
        return 0
    if False:
        # Check trivial
        found_toy = False
        for i in range( len(toys)/2 ):
            if toys[1 + i*2] == boxes[1]:
                found_toy = True
                break 
        found_box = False
        for i in range( len(boxes)/2 ):
            if boxes[1 + i*2] == toys[1]:
                found_box = True
                break
        if not found_toy:
            boxes = do_throw( boxes ) 
        if not found_box:
            toys = do_throw( toys ) 
        # Nothing left
        if len(boxes) == 0 or len(toys) == 0:
            return 0
    
    # Max without producing
    max_produced = 0 
    # max( analyze( do_throw( boxes, toys), toys  ), analyze( boxes, do_throw( toys, boxes ) ) )
    # How many to produce
    already_produced = 0
    while boxes[1] == toys[1]:
        if boxes[0] < toys[0]:
            # Toys left
            already_produced = already_produced + boxes[0]
            toys   = [ toys[0] - boxes[0], toys[1] ] + toys[2:] 
            boxes  = boxes[2:]
        elif toys[0] < boxes[0]:    
            # Boxes left 
            already_produced = already_produced + toys[0]
            boxes  = [ boxes[0] - toys[0], boxes[1] ] + boxes[2:] 
            toys   = toys[2:]
        else:
            already_produced = already_produced + toys[0]
            boxes  = boxes[2:]
            toys   = toys[2:]
        # Nothing left
        if len(boxes) == 0 or len(toys) == 0:
            break
            
    max_produced = max( max_produced, already_produced + analyze( do_throw( boxes, toys), toys  ), 
                                      already_produced + analyze( boxes, do_throw( toys, boxes ) ) )
    return max_produced 

for i in range(T):
    raw = map(int, inp.readline().split(" "))
    n_boxes = raw[0]
    n_toys  = raw[1]
    boxes   = map( int, inp.readline().split(" ") )
    toys    = map( int, inp.readline().split(" ") )
    outp.write( "Case #" + str(i+1) + ": " + str( analyze( boxes, toys ) ) + "\n")
