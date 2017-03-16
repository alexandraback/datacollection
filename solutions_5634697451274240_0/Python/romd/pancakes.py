LINES_FOR_EACH_INPUT = 1
INPUT_FILE_NAME = 'B-small-attempt0.in'
OUTPUT_FILE_NAME = 'B-small-attempt0.out'

def do_case(parsed):
        flips=0
        for i in range(len(parsed)-1):
                if parsed[i]!=parsed[i+1]:\
                   flips+=1
        return str(flips)

def do_parse(input):
        return input[0].rstrip()+'+'      

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
