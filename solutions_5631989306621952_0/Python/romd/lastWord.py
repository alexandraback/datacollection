LINES_FOR_EACH_INPUT = 1
INPUT_FILE_NAME = 'A-small-attempt0.in'
OUTPUT_FILE_NAME = 'A-small-attempt0.out'

def do_case(input):
        if(input==""):
                return ""
        cutI=input.find(max(input))
        st=do_case(input[:cutI])
        for ch in input[cutI:]:
                if ch==input[cutI]:
                        st=ch+st
                else:
                        st=st+ch
        return str(st)

def do_parse(input):
        return input[0].rstrip()

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
