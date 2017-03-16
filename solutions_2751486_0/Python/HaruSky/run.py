import sys
import time
import itertools

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

    name, n = file_in.readline().rstrip("\n").split(" ")
    n = int(n)
    L = len(name)

    #print L, name, n

    #index of first cons of the 3-group
    idx_l = []
    i = 0
    while i < L - (n - 1):
        ok = True
        for j in range(n):
            if name[i+j] not in cons_l:
                ok = False
                break
        if ok:
     #       print i
            idx_l += [i]

        i += 1

    #print idx_l

    result_l = []
    for i in idx_l:
        left = i
        right = i + (n - 1)
        while right < L:
            result_l.append([left, right])
            while left > 0:
                left -= 1
                result_l.append([left, right])
                #for j in range(left, L):
                #    if j <= i or j > i + (n - 1):
                #        print i, j
            right += 1
            left = i

    result_l.sort()
    result_l = list(result_l for result_l,_ in itertools.groupby(result_l))
    #print result_l
    #print len(result_l)

    result += " %d" % len(result_l)




    return result

if __name__ == "__main__":
    start_time = time.time()

    # Open input and output files
    file_in, file_out = open_io_files()

    # Extract the number of tests
    T = int(file_in.readline())

    cons_l = ["b","c","d","f","g","h","j","k","l","m","n","p","q","r","s","t","v","w","x","y","z"]
    vow_l  = ["a","e","i","o","u"]

    # Process every test and write to file
    for test_id in range(1, T+1):
        result = process_test(test_id)
        if file_out:
            file_out.write(result + "\n")
        else:
            print result

    time = time.time() - start_time
    print "%s executed in %g seconds." % (sys.argv[0], time)
