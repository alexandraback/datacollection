//============================================================================
// Name        : Cookie_Clicker_Alpha.cpp
// Author      : von Bergen, Federico
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <fstream>
#include <ios>
#include <iostream>
using std::cerr;
using std::endl;
#include <iomanip>
#include <string>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <vector>

#include "Cookie_Clicker_Alpha.h"
#include "defines.h"

int main(void){
	std::ifstream input_file(INPUT_FILENAME,std::ifstream::in);
	std::ofstream output_file(OUTPUT_FILENAME,std::ifstream::out);
	std::string line;
	std::size_t substr_start = 0,substr_end = std::string::npos;
	std::vector<std::string> case_information;
	char ** endptr = NULL;
	size_t case_number,quant_test_cases;
	double cookies_rate,farm_cookies_cost,farm_extra_cookies_per_second,quant_cookies_to_win,minimum_time,aux_minimum_time,total_farm_time_cost;

	try{
		if(input_file.fail())
			throw std::runtime_error("The input file couldn't be opened.");
		if(output_file.fail())
			throw std::runtime_error("The output file couldn't be opened.");
		getline(input_file,line);
		quant_test_cases = strtol(line.c_str(),endptr,10);
		if(endptr != NULL)
			throw std::runtime_error("The input file is incorrect.");
		if(quant_test_cases < MIN_QUANT_TEST_CASES || quant_test_cases > MAX_QUANT_TEST_CASES)
			throw std::runtime_error("The number of cases isn't within the limits.");
		for(case_number = 0;input_file.good() && case_number < quant_test_cases;case_number++){
			/*Read from input file.*/
			getline(input_file,line);
			substr_start = 0;
			substr_end = line.find(INPUT_FILE_DELIMITER,substr_start);
			case_information.push_back(line.substr(substr_start,substr_end));
			while(substr_end != std::string::npos){
				substr_start = ++substr_end;
				substr_end = line.find(INPUT_FILE_DELIMITER,substr_start);
				case_information.push_back(line.substr(substr_start,substr_end-substr_start));
			}
			/*Validate and load the answers.*/
			if(case_information.size() != COLUMNS_PER_ROW)
				throw std::runtime_error("The input file is incorrect.");
			farm_cookies_cost = strtod(case_information[FARM_COOKIES_COST_POS].c_str(),endptr);
			if(endptr != NULL)
				throw std::runtime_error("The input file is incorrect.");
			if(farm_cookies_cost < MIN_FARM_COOKIES_COST || farm_cookies_cost > MAX_FARM_COOKIES_COST)
				throw std::runtime_error("The farm cost number isn't within the limits.");
			farm_extra_cookies_per_second = strtod(case_information[FARM_EXTRA_COOKIES_PER_SECOND_POS].c_str(),endptr);
			if(endptr != NULL)
				throw std::runtime_error("The input file is incorrect.");
			if(farm_extra_cookies_per_second < MIN_FARM_EXTRA_COOKIES_PER_SECOND || farm_extra_cookies_per_second > MAX_FARM_EXTRA_COOKIES_PER_SECOND)
				throw std::runtime_error("The farm extra cookies per second number isn't within the limits.");
			quant_cookies_to_win = strtod(case_information[QUANT_COOKIES_TO_WIN_POS].c_str(),endptr);
			if(endptr != NULL)
				throw std::runtime_error("The input file is incorrect.");
			if(quant_cookies_to_win < MIN_QUANT_COOKIES_TO_WIN || quant_cookies_to_win > MAX_QUANT_COOKIES_TO_WIN)
				throw std::runtime_error("The quantity of cookies to win number isn't within the limits.");
			/*Calculate the minimum time.*/
			cookies_rate = BASE_COOKIES_RATE;
			minimum_time = quant_cookies_to_win/cookies_rate;
			cookies_rate += farm_extra_cookies_per_second;
			total_farm_time_cost = farm_cookies_cost/BASE_COOKIES_RATE;
			aux_minimum_time = total_farm_time_cost + quant_cookies_to_win/cookies_rate;
			while(aux_minimum_time < minimum_time){
				minimum_time = aux_minimum_time;
				total_farm_time_cost += farm_cookies_cost/cookies_rate;
				cookies_rate += farm_extra_cookies_per_second;
				aux_minimum_time = total_farm_time_cost + quant_cookies_to_win/cookies_rate;
			}
		std::cout << endl;
			/*Write to output file.*/
			output_file << "Case" << CHAR_SPACE << CHAR_NUMBER_SIGN << case_number + 1 << CHAR_COLON << CHAR_SPACE << std::fixed << std::setprecision(7) << minimum_time << endl;
			/*Clear information to use the information variable again.*/
			case_information.clear();
		}
		getline(input_file,line);	/*Read the last empty line.*/
		if(!input_file.eof())
			throw std::runtime_error("There was an error reading the input file.");
		input_file.close();
		output_file.close();
		if(quant_test_cases != case_number)
			throw std::runtime_error("The input file doesn't contain the amount of cases declared in the header.");
	}
	catch(std::runtime_error & exception){
		cerr << "Cookie_Clicker_Alpha:" << CHAR_SPACE << exception.what() << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
