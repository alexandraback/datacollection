import sys
import time
from random import *

def open_io_files():
    assert len(sys.argv) > 1, "Error: missing input file name argument."

    try:
        input_filename = sys.argv[1]
        file_in = open(input_filename, "r")
        print "Opening file \"%s\" in read." %  input_filename
    except:
        assert False, "Error, could not read file \"%s\"." % input_filename

    if len(sys.argv) > 2:
        try:
            output_filename = sys.argv[2]
            file_out = open(output_filename, "w")
            print "Opening file \"%s\" in write." % output_filename
        except:
            assert False, "Error: could not write file \"%s\"." % output_filename
    else:
        print "Warning: no output file given as argument."
        file_out = None

    return file_in, file_out

def process_test(test_id):
    result = "Case #%d:" % test_id

    X, Y = map(int, file_in.readline().split(" "))
    #print X, Y

    while True:
        value = 0
        cur_X = 0
        cur_Y = 0
        cur_result = []
        found = False
        avail_l = []
        if X != 0:
            avail_l += ["E", "W"]
        if Y != 0:
            avail_l += ["N", "S"]

        for i in range(500):
            #print cur_X, cur_Y
            value += 1

            direction = choice(avail_l)
            cur_result.append(direction)

            if direction == "E":
                #print "E", value, cur_X, cur_X + value
                cur_X += value
            elif direction == "W":
                #print "W"
                cur_X -= value
            elif direction == "N":
                #print "N"
                cur_Y += value
            else:
                #print "S"
                cur_Y -= value

            if cur_X == X and cur_Y == Y:
                found = True
                #print "Found"
                break
            elif abs(cur_X) > 10 * abs(X) or abs(cur_Y) > 10 * abs(Y):
                break

        if found:
            result += " %s" % "".join(cur_result)
            break

    return result

if __name__ == "__main__":
    start_time = time.time()

    # Open input and output files
    file_in, file_out = open_io_files()

    # Extract the number of tests
    T = int(file_in.readline())

    # Process every test and write to file
    for test_id in range(1, T+1):
        result = process_test(test_id)
        if file_out:
            print result
            file_out.write(result + "\n")
        else:
            print result

    time = time.time() - start_time
    print "%s executed in %g seconds." % (sys.argv[0], time)
