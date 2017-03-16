LINES_FOR_EACH_INPUT = 1
INPUT_FILE_NAME = 'A-small-attempt0.in'
OUTPUT_FILE_NAME = 'output.txt'

def do_case(parsed_input):
        Max=0
        sum=0
        for i in parsed_input:
                sum=sum+1-int(i)
                Max=max(Max,sum)

        return str(Max)

def do_parse(input):
        return input[0].split(" ")[1].rstrip()
        

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
