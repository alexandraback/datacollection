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

#include "Minesweeper_Master.h"
#include "defines.h"

int main(void){
	std::ifstream input_file(INPUT_FILENAME,std::ifstream::in);
	std::ofstream output_file(OUTPUT_FILENAME,std::ifstream::out);
	std::string line;
	std::size_t substr_start = 0,substr_end = std::string::npos;
	std::vector<std::string> case_information;
	char ** endptr = NULL;
	size_t case_number,quant_test_cases,mines_set,rows,columns,mines,rows_left,columns_left,i,j,k,l;
	int aux_rows,aux_columns,aux_mines;
	std::vector< std::vector<char> > matrix(CHAR_FULL_STOP);
	bool is_possible;

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
			/*Validate and load the grid.*/
			if(case_information.size() != COLUMNS_PER_ROW)
				throw std::runtime_error("The input file is incorrect.");
			aux_rows = strtol(case_information[ROWS_POS].c_str(),endptr,10);
			if(endptr != NULL)
				throw std::runtime_error("The input file is incorrect.");
			if(aux_rows < MIN_ROWS || aux_rows > MAX_ROWS)
				throw std::runtime_error("The rows number isn't within the limits.");
			rows = aux_rows;
			aux_columns = strtol(case_information[COLUMNS_POS].c_str(),endptr,10);
			if(endptr != NULL)
				throw std::runtime_error("The input file is incorrect.");
			if(aux_columns < MIN_COLUMNS || aux_columns > MAX_COLUMNS)
				throw std::runtime_error("The columns number isn't within the limits.");
			columns = aux_columns;
			aux_mines = strtol(case_information[MINES_POS].c_str(),endptr,10);
			if(endptr != NULL)
				throw std::runtime_error("The input file is incorrect.");
			if(aux_mines < MIN_MINES || aux_mines > aux_rows*aux_columns)
				throw std::runtime_error("The mines number isn't within the limits.");
			mines = aux_mines;
			/*Create Matrix.*/
			matrix.resize(rows);
			for(i = 0;i < rows;i++)
				matrix[i].resize(columns,CHAR_FULL_STOP);
			/*Analyze the cases.*/
			mines_set = 0;
			/*There are the same amount of mines as cells.*/
			is_possible = true;
			if(mines > rows*columns - 1)
				is_possible = false;
			/*The only free is c.*/
			else if(mines == rows*columns - 1){
				matrix[rows - 1][columns - 1] = CHAR_C_LOWERCASE;
				for(i = 0;i < rows && mines_set < mines;i++){
					if(i != rows - 1){
						for(j = 0;j < columns && mines_set < mines;j++){
							matrix[i][j] = CHAR_ASTERISK;
							mines_set++;
						}
					}
					else{
						for(j = 0;j < columns - 1 && mines_set < mines;j++){
							matrix[i][j] = CHAR_ASTERISK;
							mines_set++;
						}
					}
				}
			}
			else if(mines == 0)
				matrix[rows - 1][columns - 1] = CHAR_C_LOWERCASE;
			else if(rows == 1 || columns == 1){
				if(rows == 1){
					matrix[0][columns - 1] = CHAR_C_LOWERCASE;
					for(i = 0;i < mines;i++)
						matrix[0][i] = CHAR_ASTERISK;
				}
				else{
					matrix[rows - 1][0] = CHAR_C_LOWERCASE;
					for(i = 0;i < mines;i++)
						matrix[i][0] = CHAR_ASTERISK;
				}
			}
			else if(mines == rows*columns - 3 || mines == rows*columns - 2)
				is_possible = false;
			else if(mines == 1){
				if(rows > 2 && columns > 2){
					matrix[rows - 1][columns - 1] = CHAR_C_LOWERCASE;
					matrix[0][0] = CHAR_ASTERISK;
				}
				else
					is_possible = false;
			}
			else if(rows == 2 || columns == 2){
				matrix[rows - 1][columns - 1] = CHAR_C_LOWERCASE;
				if(rows == 2 && columns == 2)
					is_possible = false;
				if(!(mines%2)){
					if(rows == 2){
						for(j = 0;mines_set < mines;j++){
							matrix[0][j] = CHAR_ASTERISK;
							matrix[1][j] = CHAR_ASTERISK;
							mines_set++;
							mines_set++;
						}
					}
					else{
						for(i = 0;mines_set < mines;i++){
							matrix[i][0] = CHAR_ASTERISK;
							matrix[i][1] = CHAR_ASTERISK;
							mines_set++;
							mines_set++;
						}
					}
				}
				else
					is_possible = false;
			}
			else{
				matrix[rows - 1][columns - 1] = CHAR_C_LOWERCASE;
				rows_left = rows;
				columns_left = columns;
				if(rows < columns){
					for(j = 0;j < columns - rows && mines_set < mines;j++){
						for(i = 0;i < rows && mines_set < mines;i++){
							if(i != rows - 2){
								matrix[i][j] = CHAR_ASTERISK;
								mines_set++;
							}
							else{
								if(mines - mines_set > 1){
									matrix[i][j] = CHAR_ASTERISK;
									mines_set++;
								}
								else
									break;
							}
						}
						columns_left--;
					}
				}
				else if(rows > columns){
					for(i = 0;i < rows - columns && mines_set < mines;i++){
						for(j = 0;j < columns && mines_set < mines;j++){
							if(j != columns - 2){
								matrix[i][j] = CHAR_ASTERISK;
								mines_set++;
							}
							else{
								if(mines - mines_set > 1){
									matrix[i][j] = CHAR_ASTERISK;
									mines_set++;
								}
								else
									break;
							}
						}
						rows_left--;
					}
				}
				k = rows - rows_left;
				l = columns - columns_left;
				while(mines - mines_set > rows_left + columns_left - 1 - 1){
					for(i = k;i < rows;i++){
						matrix[i][l] = CHAR_ASTERISK;
						mines_set++;
					}
					l++;
					for(j = l;j < columns;j++){
						matrix[k][j] = CHAR_ASTERISK;
						mines_set++;
					}
					k++;
					rows_left--;
					columns_left--;
				}
				for(i = k;k < rows && mines_set < mines;i++){
					if(i != rows - 2){
						for(j = l;j < columns && mines_set < mines;j++){
							if(j != columns - 2){
								matrix[i][j] = CHAR_ASTERISK;
								mines_set++;
							}
							else{
								if(mines - mines_set > 1){
									matrix[i][j] = CHAR_ASTERISK;
									mines_set++;
								}
								else
									break;
							}
						}
					}
					else{
						for(j = l;j < columns - 2 && mines_set < mines;l++){
							if(mines - mines_set > 1){
								matrix[rows - 2][l] = CHAR_ASTERISK;
								matrix[rows - 1][l] = CHAR_ASTERISK;
								mines_set++;
								mines_set++;
							}
							else{
								is_possible = false;
								break;
							}
						}
					}
				}
			}
			/*Write to output file.*/
			if(is_possible == true){
				output_file << "Case" << CHAR_SPACE << CHAR_NUMBER_SIGN << case_number + 1 << CHAR_COLON << endl;
				for(i = 0;i < rows;i++){
					for(j = 0;j < columns;j++){
						output_file << matrix[i][j];
					}
					output_file << endl;
				}
			}
			else{
				output_file << "Case" << CHAR_SPACE << CHAR_NUMBER_SIGN << case_number + 1 << CHAR_COLON << endl;
				output_file << "Impossible" << endl;
			}
			/*Clear information to use the information variable again.*/
			case_information.clear();
			for(i = rows - 1;i + 1 > 0;i--)
				matrix[i].clear();
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
		cerr << "Minesweeper_Master:" << CHAR_SPACE << exception.what() << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
