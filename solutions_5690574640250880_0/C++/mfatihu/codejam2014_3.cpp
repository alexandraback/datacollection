/*
 * File:   main.cpp
 * Author: mehmetfatihuslu
 *
 * Created on April 12, 2014, 4:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;


int main(int argc, char** argv) {

    fstream inputFile, outputFile, logFile;
    int T,R,C,M;

    inputFile.open("input",ios::in);
    outputFile.open("output",ios::out);
    logFile.open("log",ios::out);

    inputFile >> T;

    for(int dongu=1; dongu<=T; dongu++) {

    	inputFile >>R>>C>>M;

        outputFile << "Case #" <<dongu <<": ";

        switch(R){

			case 1:{

				switch(C){

					case 1:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c";
								break;
							}
						}
						break;
					}
					case 2:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<".c";
								break;
							}
							case 1:{

								outputFile<<"*c";
								break;
							}
						}
						break;
					}
					case 3:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"..c";
								break;
							}
							case 1:{

								outputFile<<"*.c";
								break;
							}
							case 2:{

								outputFile<<"**c";
								break;
							}
						}
						break;
					}
					case 4:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"...c";
								break;
							}
							case 1:{

								outputFile<<"*..c";
								break;
							}
							case 2:{

								outputFile<<"**.c";
								break;
							}
							case 3:{

								outputFile<<"***c";
								break;
							}
						}
						break;
					}
					case 5:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"....c";
								break;
							}
							case 1:{

								outputFile<<"*...c";
								break;
							}
							case 2:{

								outputFile<<"**..c";
								break;
							}
							case 3:{

								outputFile<<"***.c";
								break;
							}
							case 4:{

								outputFile<<"****c";
								break;
							}
						}
						break;
					}
					break;
				}
				break;
			}
			case 2:{

				switch(C){

					case 1:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c"<<endl<<".";
								break;
							}
							case 1:{

								outputFile<<"*"<<endl<<"c";
								break;
							}
						}
						break;
					}
					case 2:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c."<<endl<<"..";
								break;
							}
							case 1:{

								outputFile<<"Impossible";
								break;
							}
							case 2:{

								outputFile<<"Impossible";
								break;
							}
							case 3:{

								outputFile<<"c*"<<endl<<"**";
								break;
							}
						}
						break;
					}
					case 3:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c.."<<endl<<"...";
								break;
							}
							case 1:{

								outputFile<<"Impossible";
								break;
							}
							case 2:{

								outputFile<<"*.c"<<endl<<"*..";
								break;
							}
							case 3:{

								outputFile<<"Impossible";
								break;
							}
							case 4:{

								outputFile<<"Impossible";
								break;
							}
							case 5:{

								outputFile<<"c**"<<endl<<"***";
								break;
							}
						}
						break;
					}
					case 4:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c..."<<endl<<"....";
								break;
							}
							case 1:{

								outputFile<<"Impossible";
								break;
							}
							case 2:{

								outputFile<<"c..*"<<endl<<"...*";
								break;
							}
							case 3:{

								outputFile<<"Impossible";
								break;
							}
							case 4:{

								outputFile<<"c.**"<<endl<<"..**";
								break;
							}
							case 5:{

								outputFile<<"Impossible";
								break;
							}
							case 6:{

								outputFile<<"Impossible";
								break;
							}
							case 7:{

								outputFile<<"c***"<<endl<<"****";
								break;
							}
						}
						break;
					}
					case 5:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c...."<<endl<<".....";
								break;
							}
							case 1:{

								outputFile<<"Impossible";
								break;
							}
							case 2:{

								outputFile<<"*.c.."<<endl<<"*....";
								break;
							}
							case 3:{

								outputFile<<"Impossible";
								break;
							}
							case 4:{

								outputFile<<"c..**"<<endl<<"...**";
								break;
							}
							case 5:{

								outputFile<<"Impossible";
								break;
							}
							case 6:{

								outputFile<<"c.***"<<endl<<"..***";
								break;
							}
							case 7:{

								outputFile<<"Impossible";
								break;
							}
							case 8:{

								outputFile<<"Impossible";
								break;
							}
							case 9:{

								outputFile<<"c****"<<endl<<"*****";
								break;
							}
							break;
						}
						break;
					}
					break;
				}
				break;
			}
			case 3:{

				switch(C){

					case 1:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c"<<endl<<"."<<endl<<".";
								break;
							}
							case 1:{

								outputFile<<"c"<<endl<<"."<<endl<<"*";
								break;
							}
							case 2:{

								outputFile<<"c"<<endl<<"*"<<endl<<"*";
								break;
							}
							break;
						}
						break;
					}
					case 2:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c."<<endl<<".."<<endl<<"..";
								break;
							}
							case 1:{

								outputFile<<"Impossible";
								break;
							}
							case 2:{

								outputFile<<"c."<<endl<<".."<<endl<<"**";
								break;
							}
							case 3:{

								outputFile<<"Impossible";
								break;
							}
							case 4:{

								outputFile<<"Impossible";
								break;
							}
							case 5:{

								outputFile<<"c*"<<endl<<"**"<<endl<<"**";
								break;
							}
							break;
						}
						break;
					}
					case 3:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"..."<<endl<<"..."<<endl<<"..c";
								break;
							}
							case 1:{

								outputFile<<"*.."<<endl<<"..."<<endl<<"..c";
								break;
							}
							case 2:{

								outputFile<<"Impossible";
								break;
							}
							case 3:{

								outputFile<<"***"<<endl<<"..."<<endl<<"..c";
								break;
							}
							case 4:{

								outputFile<<"Impossible";
								break;
							}
							case 5:{

								outputFile<<"***"<<endl<<"*.."<<endl<<"*.c";
								break;
							}
							case 6:{

								outputFile<<"Impossible";
								break;
							}
							case 7:{

								outputFile<<"Impossible";
								break;
							}
							case 8:{

								outputFile<<"***"<<endl<<"***"<<endl<<"**c";
								break;
							}
							break;
						}
						break;
					}
					case 4:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"...."<<endl<<"...."<<endl<<"...c";
								break;
							}
							case 1:{

								outputFile<<"*..."<<endl<<"...."<<endl<<"...c";
								break;
							}
							case 2:{

								outputFile<<"**.."<<endl<<"...."<<endl<<"...c";
								break;
							}
							case 3:{

								outputFile<<"*..."<<endl<<"*..."<<endl<<"*..c";
								break;
							}
							case 4:{

								outputFile<<"****"<<endl<<"...."<<endl<<"...c";
								break;
							}
							case 5:{

								outputFile<<"Impossible";
								break;
							}
							case 6:{

								outputFile<<"**.."<<endl<<"**.."<<endl<<"**.c";
								break;
							}
							case 7:{

								outputFile<<"Impossible";
								break;
							}
							case 8:{

								outputFile<<"****"<<endl<<"**.."<<endl<<"**.c";
								break;
							}
							case 9:{

								outputFile<<"Impossible";
								break;
							}
							case 10:{

								outputFile<<"Impossible";
								break;
							}
							case 11:{

								outputFile<<"****"<<endl<<"****"<<endl<<"***c";
								break;
							}
							break;
						}
						break;
					}
					case 5:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"....."<<endl<<"....."<<endl<<"....c";
								break;
							}
							case 1:{

								outputFile<<"*...."<<endl<<"....."<<endl<<"....c";
								break;
							}
							case 2:{

								outputFile<<"**..."<<endl<<"....."<<endl<<"....c";
								break;
							}
							case 3:{

								outputFile<<"*...."<<endl<<"*...."<<endl<<"*...c";
								break;
							}
							case 4:{

								outputFile<<"**..."<<endl<<"*...."<<endl<<"*...c";
								break;
							}
							case 5:{

								outputFile<<"***.."<<endl<<"*...."<<endl<<"*...c";
								break;
							}
							case 6:{

								outputFile<<"**..."<<endl<<"**..."<<endl<<"**..c";
								break;
							}
							case 7:{

								outputFile<<"***.."<<endl<<"**..."<<endl<<"**..c";
								break;
							}
							case 8:{

								outputFile<<"Impossible";
								break;
							}
							case 9:{

								outputFile<<"***.."<<endl<<"***.."<<endl<<"***.c";
								break;
							}
							case 10:{

								outputFile<<"Impossible";
								break;
							}
							case 11:{

								outputFile<<"*****"<<endl<<"***.."<<endl<<"***.c";
								break;
							}
							break;
							case 12:{

								outputFile<<"Impossible";
								break;
							}
							case 13:{

								outputFile<<"Impossible";
								break;
							}
							case 14:{

								outputFile<<"*****"<<endl<<"*****"<<endl<<"****c";
								break;
							}
							break;
						}
						break;
					}
					break;
				}
				break;

			}
			case 4:{

				switch(C){

					case 1:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c"<<endl<<"."<<endl<<"."<<endl<<".";
								break;
							}
							case 1:{

								outputFile<<"c"<<endl<<"."<<endl<<"."<<endl<<"*";
								break;
							}
							case 2:{

								outputFile<<"c"<<endl<<"."<<endl<<"*"<<endl<<"*";
								break;
							}
							case 3:{

								outputFile<<"c"<<endl<<"*"<<endl<<"*"<<endl<<"*";
								break;
							}
						}
						break;
					}
					case 2:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c."<<endl<<".."<<endl<<".."<<endl<<"..";
								break;
							}
							case 1:{

								outputFile<<"Impossible";
								break;
							}
							case 2:{

								outputFile<<"c."<<endl<<".."<<endl<<".."<<endl<<"**";
								break;
							}
							case 3:{

								outputFile<<"Impossible";
								break;
							}
							case 4:{

								outputFile<<"c."<<endl<<".."<<endl<<"**"<<endl<<"**";
								break;
							}
							case 5:{

								outputFile<<"Impossible";
								break;
							}
							case 6:{

								outputFile<<"Impossible";
								break;
							}
							case 7:{

								outputFile<<"c*"<<endl<<"**"<<endl<<"**"<<endl<<"**";
								break;
							}
						}
						break;
					}
					case 3:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..."<<endl<<"...";
								break;
							}
							case 1:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..."<<endl<<"..*";
								break;
							}
							case 2:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..*"<<endl<<"..*";
								break;
							}
							case 3:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..."<<endl<<"***";
								break;
							}
							case 4:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..*"<<endl<<"***";
								break;
							}
							case 5:{

								outputFile<<"Impossible";
								break;
							}
							case 6:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"***"<<endl<<"***";
								break;
							}
							case 7:{

								outputFile<<"Impossible";
								break;
							}
							case 8:{

								outputFile<<"c.*"<<endl<<"..*"<<endl<<"***"<<endl<<"***";
								break;
							}
							case 9:{

								outputFile<<"Impossible";
								break;
							}
							case 10:{

								outputFile<<"Impossible";
								break;
							}
							case 11:{

								outputFile<<"c**"<<endl<<"***"<<endl<<"***"<<endl<<"***";
								break;
							}
						}
						break;
					}
					case 4:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...."<<endl<<"....";
								break;
							}
							case 1:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...."<<endl<<"...*";
								break;
							}
							case 2:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...*"<<endl<<"...*";
								break;
							}
							case 3:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...*"<<endl<<"..**";
								break;
							}
							case 4:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...."<<endl<<"****";
								break;
							}
							case 5:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...*"<<endl<<"****";
								break;
							}
							case 6:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"..**"<<endl<<"****";
								break;
							}
							case 7:{

								outputFile<<"c..*"<<endl<<"...*"<<endl<<"...*"<<endl<<"****";
								break;
							}
							case 8:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"****"<<endl<<"****";
								break;
							}
							case 9:{

								outputFile<<"Impossible";
								break;
							}
							case 10:{

								outputFile<<"c..*"<<endl<<"...*"<<endl<<"****"<<endl<<"****";
								break;
							}
							case 11:{

								outputFile<<"Impossible";
								break;
							}
							case 12:{

								outputFile<<"c.**"<<endl<<"..**"<<endl<<"****"<<endl<<"****";
								break;
							}
							case 13:{

								outputFile<<"Impossible";
								break;
							}
							case 14:{

								outputFile<<"Impossible";
								break;
							}
							case 15:{

								outputFile<<"c***"<<endl<<"****"<<endl<<"****"<<endl<<"****";
								break;
							}
						}
						break;
					}
					case 5:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<".....";
								break;
							}
							case 1:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"....*";
								break;
							}
							case 2:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....*"<<endl<<"....*";
								break;
							}
							case 3:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"..***";
								break;
							}
							case 4:{

								outputFile<<"c...*"<<endl<<"....*"<<endl<<"....*"<<endl<<"....*";
								break;
							}
							case 5:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"*****";
								break;
							}
							case 6:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....*"<<endl<<"*****";
								break;
							}
							case 7:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"...**"<<endl<<"*****";
								break;
							}
							case 8:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"..***"<<endl<<"*****";
								break;
							}
							case 9:{

								outputFile<<"c..**"<<endl<<"...**"<<endl<<"...**"<<endl<<"..***";
								break;
							}
							case 10:{

								outputFile<<"c..**"<<endl<<"...**"<<endl<<"..***"<<endl<<"..***";
								break;
							}
							case 11:{

								outputFile<<"c..**"<<endl<<"...**"<<endl<<"...**"<<endl<<"*****";
								break;
							}
							case 12:{

								outputFile<<"c.***"<<endl<<"..***"<<endl<<"..***"<<endl<<"..***";
								break;
							}
							case 13:{

								outputFile<<"Impossible";
								break;
							}
							case 14:{

								outputFile<<"c.***"<<endl<<"..***"<<endl<<"..***"<<endl<<"*****";
								break;
							}
							case 15:{

								outputFile<<"Impossible";
								break;
							}
							case 16:{

								outputFile<<"c.***"<<endl<<"..***"<<endl<<"*****"<<endl<<"*****";
								break;
							}
							case 17:{

								outputFile<<"Impossible";
								break;
							}
							case 18:{

								outputFile<<"Impossible";
								break;
							}
							case 19:{

								outputFile<<"c****"<<endl<<"*****"<<endl<<"*****"<<endl<<"*****";
								break;
							}
						}
						break;
					}
					break;
				}
				break;

			}
			case 5:{

				switch(C){

					case 1:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c"<<endl<<"."<<endl<<"."<<endl<<"."<<endl<<".";
								break;
							}
							case 1:{

								outputFile<<"c"<<endl<<"."<<endl<<"."<<endl<<"."<<endl<<"*";
								break;
							}
							case 2:{

								outputFile<<"c"<<endl<<"."<<endl<<"."<<endl<<"*"<<endl<<"*";
								break;
							}
							case 3:{

								outputFile<<"c"<<endl<<"."<<endl<<"*"<<endl<<"*"<<endl<<"*";
								break;
							}
							case 4:{

								outputFile<<"c"<<endl<<"*"<<endl<<"*"<<endl<<"*"<<endl<<"*";
								break;
							}
						}
						break;
					}
					case 2:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c."<<endl<<".."<<endl<<".."<<endl<<".."<<endl<<"..";
								break;
							}
							case 1:{

								outputFile<<"Impossible";
								break;
							}
							case 2:{

								outputFile<<"c."<<endl<<".."<<endl<<".."<<endl<<".."<<endl<<"**";
								break;
							}
							case 3:{

								outputFile<<"Impossible";
								break;
							}
							case 4:{

								outputFile<<"c."<<endl<<".."<<endl<<".."<<endl<<"**"<<endl<<"**";
								break;
							}
							case 5:{

								outputFile<<"Impossible";
								break;
							}
							case 6:{

								outputFile<<"c."<<endl<<".."<<endl<<"**"<<endl<<"**"<<endl<<"**";
								break;
							}
							case 7:{

								outputFile<<"Impossible";
								break;
							}
							case 8:{

								outputFile<<"Impossible";
								break;
							}
							case 9:{

								outputFile<<"c*"<<endl<<"**"<<endl<<"**"<<endl<<"**"<<endl<<"**";
								break;
							}
						}
						break;
					}
					case 3:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..."<<endl<<"..."<<endl<<"...";
								break;
							}
							case 1:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..."<<endl<<"..."<<endl<<"..*";
								break;
							}
							case 2:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..."<<endl<<"..*"<<endl<<"..*";
								break;
							}
							case 3:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..."<<endl<<"..."<<endl<<"***";
								break;
							}
							case 4:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..."<<endl<<"..*"<<endl<<"***";
								break;
							}
							case 5:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..*"<<endl<<"..*"<<endl<<"***";
								break;
							}
							case 6:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..."<<endl<<"***"<<endl<<"***";
								break;
							}
							case 7:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"..*"<<endl<<"***"<<endl<<"***";
								break;
							}
							case 8:{

								outputFile<<"Impossible";
								break;
							}
							case 9:{

								outputFile<<"c.."<<endl<<"..."<<endl<<"***"<<endl<<"***"<<endl<<"***";
								break;
							}
							case 10:{

								outputFile<<"Impossible";
								break;
							}
							case 11:{

								outputFile<<"c.*"<<endl<<"..*"<<endl<<"***"<<endl<<"***"<<endl<<"***";
								break;
							}
							case 12:{

								outputFile<<"Impossible";
								break;
							}
							case 13:{

								outputFile<<"Impossible";
								break;
							}
							case 14:{

								outputFile<<"c**"<<endl<<"***"<<endl<<"***"<<endl<<"***"<<endl<<"***";
								break;
							}
						}
						break;
					}
					case 4:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...."<<endl<<"...."<<endl<<"....";
								break;
							}
							case 1:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...."<<endl<<"...."<<endl<<"...*";
								break;
							}
							case 2:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...."<<endl<<"...*"<<endl<<"...*";
								break;
							}
							case 3:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...*"<<endl<<"...*"<<endl<<"...*";
								break;
							}
							case 4:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...."<<endl<<"...."<<endl<<"****";
								break;
							}
							case 5:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...*"<<endl<<"..**"<<endl<<"..**";
								break;
							}
							case 6:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...."<<endl<<"..**"<<endl<<"****";
								break;
							}
							case 7:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...*"<<endl<<"..**"<<endl<<"****";
								break;
							}
							case 8:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...."<<endl<<"****"<<endl<<"****";
								break;
							}
							case 9:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"...*"<<endl<<"****"<<endl<<"****";
								break;
							}
							case 10:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"..**"<<endl<<"****"<<endl<<"****";
								break;
							}
							case 11:{

								outputFile<<"c..*"<<endl<<"...*"<<endl<<"...*"<<endl<<"****"<<endl<<"****";
								break;
							}
							case 12:{

								outputFile<<"c..."<<endl<<"...."<<endl<<"****"<<endl<<"****"<<endl<<"****";
								break;
							}
							case 13:{

								outputFile<<"Impossible";
								break;
							}
							case 14:{

								outputFile<<"c..*"<<endl<<"...*"<<endl<<"****"<<endl<<"****"<<endl<<"****";
								break;
							}
							case 15:{

								outputFile<<"Impossible";
								break;
							}
							case 16:{

								outputFile<<"c.**"<<endl<<"..**"<<endl<<"****"<<endl<<"****"<<endl<<"****";
								break;
							}
							case 17:{

								outputFile<<"Impossible";
								break;
							}
							case 18:{

								outputFile<<"Impossible";
								break;
							}
							case 19:{

								outputFile<<"c***"<<endl<<"****"<<endl<<"****"<<endl<<"****"<<endl<<"****";
								break;
							}
						}
						break;
					}
					case 5:{

						outputFile<<endl;
						switch(M){

							case 0:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"....."<<endl<<".....";
								break;
							}
							case 1:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"....."<<endl<<"....*";
								break;
							}
							case 2:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"....*"<<endl<<"....*";
								break;
							}
							case 3:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....*"<<endl<<"....*"<<endl<<"....*";
								break;
							}
							case 4:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"...**"<<endl<<"...**";
								break;
							}
							case 5:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....*"<<endl<<"...**"<<endl<<"...**";
								break;
							}
							case 6:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"..***"<<endl<<"..***";
								break;
							}
							case 7:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"...**"<<endl<<"*****";
								break;
							}
							case 8:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"....."<<endl<<"..***"<<endl<<"*****";
								break;
							}
							case 9:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"...**"<<endl<<"...**"<<endl<<"*****";
								break;
							}
							case 10:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"...**"<<endl<<"..***"<<endl<<"*****";
								break;
							}
							case 11:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"..***"<<endl<<"..***"<<endl<<"*****";
								break;
							}
							case 12:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"...**"<<endl<<"*****"<<endl<<"*****";
								break;
							}
							case 13:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"..***"<<endl<<"*****"<<endl<<"*****";
								break;
							}
							case 14:{

								outputFile<<"c...*"<<endl<<"....*"<<endl<<"...**"<<endl<<"*****"<<endl<<"*****";
								break;
							}
							case 15:{

								outputFile<<"c...."<<endl<<"....."<<endl<<"*****"<<endl<<"*****"<<endl<<"*****";
								break;
							}
							case 16:{

								outputFile<<"c..**"<<endl<<"...**"<<endl<<"...**"<<endl<<"*****"<<endl<<"*****";
								break;
							}
							case 17:{

								outputFile<<"c...*"<<endl<<"....*"<<endl<<"*****"<<endl<<"*****"<<endl<<"*****";
								break;
							}
							case 18:{

								outputFile<<"Impossible";
								break;
							}
							case 19:{

								outputFile<<"c..**"<<endl<<"...**"<<endl<<"*****"<<endl<<"*****"<<endl<<"*****";
								break;
							}
							case 20:{

								outputFile<<"Impossible";
								break;
							}
							case 21:{

								outputFile<<"c.***"<<endl<<"..***"<<endl<<"*****"<<endl<<"*****"<<endl<<"*****";
								break;
							}
							case 22:{

								outputFile<<"Impossible";
								break;
							}
							case 23:{

								outputFile<<"Impossible";
								break;
							}
							case 24:{

								outputFile<<"c****"<<endl<<"*****"<<endl<<"*****"<<endl<<"*****"<<endl<<"*****";
								break;
							}
						}
						break;
					}
					break;
				}
			}
        }
        outputFile<<endl;
    }

    return 0;
}

