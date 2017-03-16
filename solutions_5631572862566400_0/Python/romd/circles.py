LINES_FOR_EACH_INPUT = 2
INPUT_FILE_NAME = 'C-small-attempt0.in'
OUTPUT_FILE_NAME = 'C-small-attempt0.out'

def do_case(input):
        circ=[0 for i in input]
        for i in range(len(circ)):
                circL=1
                temp=input[i]
                while temp-1!=i and circL<len(circ)+1:
                        circL+=1
                        temp=input[temp-1]
                circ[i]=circL
                if circ[i]==len(circ)+1:
                        circ[i]=0
        seg=[0 for i in input]
        for i in range(len(circ)):
                if circ[i]==2:
                        seg[i]=max(seg[i],1)
                if circ[i]==0:
                        Seg=1
                        temp=input[i]
                        while circ[temp-1]==0:
                                Seg+=1
                                temp=input[temp-1]
                        if circ[temp-1]==2:
                                seg[temp-1]=max(seg[temp-1],Seg+1)
        return str(max(max(circ),sum(seg)))

def do_parse(input):
        return [int(num) for num in input[1].rstrip().split(" ")]       

def main():
        input_f = open(INPUT_FILE_NAME, 'r')
        output = []
	
        num_of_test_cases = int(input_f.readline(), 10)
	
        input_lines = input_f.readlines()
	
        for test_case in range(num_of_test_cases):
                parsed_input = do_parse(input_lines[test_case*LINES_FOR_EACH_INPUT : (test_case + 1) * LINES_FOR_EACH_INPUT])
                output.append('Case #' + str(test_case + 1) + ': ' + do_case(parsed_input))

        output_f = open(OUTPUT_FILE_NAME, 'w')
        output_f.write('\n'.join(output))
	
        input_f.close()
        output_f.close()
	
if __name__ == '__main__':
        main()
