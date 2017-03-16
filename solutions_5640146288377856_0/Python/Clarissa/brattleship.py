"""
Time to play some brattleship.
"""

import fileinput #reading from stdin
import math

def main():
    #Read from stdin
    case = 1
    first_line = True
    for line in fileinput.input():
        if first_line:
            first_line = False
            continue
        
        values = [int(num) for num in line.split()];
        rows = values[0]
        cols = values[1]
        width = values[2]
        
        # Time taken to pin the piece down in all rows
        pin_time = rows*math.floor(cols/width)
        
        """
        After we've pinned down where the piece should be placed, we need to
        actually find where EXACTLY it is. We'll need to LINEAR! OOPS! search
        for it. In fact, we'll stop as soon as we hit a non-in piece. Whoops.
        """
        #One is wasted in finding the edge sometimes.
        number_moves = pin_time + width-1 + (0 if cols%width == 0 else 1)
        
        print("Case #" + str(case) + ": " + str(number_moves))
        case += 1
        
main()
